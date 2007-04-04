#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <glib.h>
#include <gtk/gtk.h>

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#include "inotify.h"
#include "inotify-syscalls.h"


#define BUF_LEN    1024

char FILE_NAME[256];  // = extern variable argv[1] in main.c
GtkWidget *pprogres, *pprogres2, *label, *label_generally, *label_clock;
static gint fd, hour = 0, min = 0, sec = 0;



static gboolean
f_notify(GIOChannel    *source, 
	 GIOCondition  condition,
	 gpointer      data)
{

   gchar column[BUF_LEN], text_current[BUF_LEN];
   char buf[BUF_LEN], *assign;
   int len, i;
   FILE *watched_file;


   while (gtk_events_pending ())
          gtk_main_iteration ();

   // stop neverending loop
   len = read (fd, buf, BUF_LEN);


   // read the changed file
   watched_file = fopen( FILE_NAME, "r" );
   if( watched_file== NULL ) {
      printf( "inotify watch file was not opened\n" );
   }
   else {
       i = 0;
       strncpy( text_current, "", BUF_LEN );
       fseek( watched_file, 0L, SEEK_SET );

       while ( fgets( column, BUF_LEN, watched_file )  != NULL ) {

             // exit main
             if( strncmp ( column, "end", 3 ) == 0 ) {
                   gtk_main_quit();
             }


             assign = strtok( column, "=");

             if ( strcmp ( assign, "PERC") == 0 ) {
                 gtk_progress_bar_set_fraction ( GTK_PROGRESS_BAR( pprogres ), strtod( strtok( NULL, "="), NULL) );
             }

             if ( strcmp ( assign, "CURRENT") == 0 ) {
                 gtk_label_set_markup ( GTK_LABEL ( label ), strtok( NULL, "=") );
             }

             if ( strcmp ( assign, "COMPLETE") == 0 ) {
                 gtk_progress_bar_set_text ( GTK_PROGRESS_BAR( pprogres ), strtok( NULL, "=") );
             }

       }


    }
    fclose( watched_file );

    gtk_progress_bar_set_fraction ( GTK_PROGRESS_BAR( pprogres2 ), 0 );

    return(TRUE);
}


gboolean up (gpointer user_data)
{
  /********************************************
   *        progresbar2 pulse                 *
   ********************************************/
   gtk_progress_bar_pulse  ( GTK_PROGRESS_BAR( pprogres2 ) );
   return(TRUE);
}


gboolean zeit (gpointer user_data)
{
  /********************************************
   *                time counter              *
   ********************************************/
   char clock[80], min0[2] = "0", sec0[2] = "0";

   sec++;
   if ( sec == 60 ) {
        sec = 0;
        min++;
   }

   if ( sec < 10)
        strncpy( sec0, "0", 2);
   else
        strncpy( sec0, "", 2);


   if ( min == 60 ) {
        min = 0;
        hour++;
   }

   if ( min < 10)
        strncpy( min0, "0", 2);
   else
        strncpy( min0, "", 2);

   sprintf (clock, "0%d:%s%d:%s%d", hour, min0, min, sec0, sec);
   gtk_label_set_text ( GTK_LABEL( label_clock ), clock );

   return(TRUE);
}


void
on_install_progressbar_show            (GtkWidget       *widget,
                                        gpointer         user_data)
{
   GdkColor color;
   PangoFontDescription *font_desc;
   GIOChannel *ioc;
   int wd;


  /********************************************
   *           PROGRESS BAR PART              *
   ********************************************/
   label = lookup_widget ( GTK_WIDGET (widget), "label1");

   font_desc = pango_font_description_from_string ("12");
   gtk_widget_modify_font ( GTK_WIDGET(label), font_desc);
   pango_font_description_free (font_desc);

   label = lookup_widget ( GTK_WIDGET (widget), "label2");
   //set color of label
   font_desc = pango_font_description_from_string ("12");
   gtk_widget_modify_font ( GTK_WIDGET(label), font_desc);
   pango_font_description_free (font_desc);



   label = lookup_widget ( GTK_WIDGET (widget), "label_fifo");

   pprogres = lookup_widget(GTK_WIDGET(widget), "progressbar1");
   font_desc = pango_font_description_from_string ("12");
   gtk_widget_modify_font ( GTK_WIDGET(pprogres), font_desc);
   pango_font_description_free (font_desc);
   // set color of ProgressBar
   gdk_color_parse ("gray70", &color);
   gtk_widget_modify_bg (pprogres, GTK_STATE_NORMAL, &color);
   gdk_color_parse ("IndianRed4", &color);
   gtk_widget_modify_bg (pprogres, GTK_STATE_PRELIGHT, &color);

   pprogres2 = lookup_widget(GTK_WIDGET(widget), "progressbar2");
   gtk_progress_bar_set_pulse_step ( GTK_PROGRESS_BAR( pprogres2 ), 0.01 );

   // set color of ProgressBar
   gdk_color_parse ("gray70", &color);
   gtk_widget_modify_bg (pprogres2, GTK_STATE_NORMAL, &color);
   gdk_color_parse ("IndianRed4", &color);
   gtk_widget_modify_bg (pprogres2, GTK_STATE_PRELIGHT, &color);

   // label_clock
   label_clock = lookup_widget ( GTK_WIDGET (widget), "label_clock");
   font_desc = pango_font_description_from_string ("Bold 12");
   gtk_widget_modify_font ( GTK_WIDGET(label_clock), font_desc);
   pango_font_description_free (font_desc);


   //  Initialize, inotify!
   fd = inotify_init();
   if (fd < 0)  perror ("inotify_init");

   //  Adding Watches
   wd = inotify_add_watch (fd, FILE_NAME, IN_MODIFY | IN_CREATE );
   if (wd < 0)  perror ("inotify_add_watch");

   ioc=g_io_channel_unix_new(fd);
   g_io_add_watch(ioc,G_IO_IN,(GIOFunc) f_notify, NULL);


   while (gtk_events_pending ())
	  gtk_main_iteration ();


  /********************************************
   *        progresbar2 pulse                 *
   ********************************************/
  g_timeout_add( 20, up, pprogres2 );
  g_timeout_add( 1000, zeit, pprogres2 );

}




