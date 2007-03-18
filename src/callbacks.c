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


/* Fifo file */
#define FIFO  "/tmp/fifo_inst"

/* reasonable guess as to size of 1024 events */
#define BUF_LEN    1024

char FIFO_FILE_NAME[256];  // = extern variable argv[1] in main.c

GtkWidget *pprogres, *pprogres2, *label;

static gint         fd;
static GIOChannel   *ioc;

int  do_it_at_first_time = 0;

static gboolean
f_notify(GIOChannel    *source, 
	 GIOCondition  condition,
	 gpointer      data)
{
   gchar  *read, *pbar_str, *text;
   gsize   size;
   GError *err;
   gchar **buf;


   while (gtk_events_pending ())
          gtk_main_iteration ();


   err = NULL;

   read = g_malloc0 ( BUF_LEN );
   g_io_channel_read_chars (source, read, BUF_LEN, &size, &err);

   buf = g_strsplit (read, "\r", 0);
   read = g_strjoinv (NULL, buf);

   if (read != NULL)
   {
       //g_print ("%s", read);

       pbar_str  = strtok( read, "~");
       text  = strtok(NULL, "~");

       gtk_label_set_markup ( GTK_LABEL ( label ), text );

       //printf("%f\n", pbar);
       gtk_progress_bar_set_fraction ( GTK_PROGRESS_BAR( pprogres ), strtod( pbar_str, NULL) );
   }
   g_strfreev (buf);


   if( strncmp ( read, "end", 3 ) == 0 ) {
       gtk_main_quit();
   }

   g_free (read);


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


void
on_install_progressbar_show            (GtkWidget       *widget,
                                        gpointer         user_data)
{
   GdkColor color;
   char *fifo;
   PangoFontDescription *font_desc;

  /********************************************
   *           PROGRESS BAR PART              *
   ********************************************/

   label = lookup_widget ( GTK_WIDGET (widget), "label1");
   //set color of label
   //gdk_color_parse ("blue", &color);
   //gtk_widget_modify_fg ( GTK_WIDGET(label), GTK_STATE_NORMAL, &color);
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


  /********************************************
   *                  fifo                    *
   ********************************************/
   //mkfifo(fifo, S_IRUSR | S_IWUSR);

   // get fifo file name from programm call option --fifo=...
   fifo = strtok(FIFO_FILE_NAME, "=");
   fifo = strtok(NULL, "=");

   fd=open(fifo, O_RDONLY);

   ioc=g_io_channel_unix_new(fd);
   g_io_add_watch(ioc,G_IO_IN,(GIOFunc) f_notify, NULL);

   while (gtk_events_pending ())
	  gtk_main_iteration ();


  /********************************************
   *        progresbar2 pulse                 *
   ********************************************/
   g_timeout_add(20, up, pprogres2);

}




