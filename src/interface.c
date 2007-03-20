/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_install_progressbar (void)
{
  GtkWidget *install_progressbar;
  GdkPixbuf *install_progressbar_icon_pixbuf;
  GtkWidget *fixed1;
  GtkWidget *progressbar1;
  GtkWidget *hseparator1;
  GtkWidget *hseparator2;
  GtkWidget *image2;
  GtkWidget *image1;
  GtkWidget *label_fifo;
  GtkWidget *progressbar2;
  GtkWidget *label1;
  GtkWidget *label2;

  install_progressbar = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (install_progressbar), _("sidux Installer"));
  gtk_window_set_resizable (GTK_WINDOW (install_progressbar), FALSE);
  install_progressbar_icon_pixbuf = create_pixbuf ("install-pgb-conf.png");
  if (install_progressbar_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (install_progressbar), install_progressbar_icon_pixbuf);
      gdk_pixbuf_unref (install_progressbar_icon_pixbuf);
    }

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (install_progressbar), fixed1);
  gtk_container_set_border_width (GTK_CONTAINER (fixed1), 15);

  progressbar1 = gtk_progress_bar_new ();
  gtk_widget_show (progressbar1);
  gtk_fixed_put (GTK_FIXED (fixed1), progressbar1, 112, 352);
  gtk_widget_set_size_request (progressbar1, 417, 25);
  gtk_progress_bar_set_pulse_step (GTK_PROGRESS_BAR (progressbar1), 0.01);

  hseparator1 = gtk_hseparator_new ();
  gtk_widget_show (hseparator1);
  gtk_fixed_put (GTK_FIXED (fixed1), hseparator1, 0, 208);
  gtk_widget_set_size_request (hseparator1, 529, 17);

  hseparator2 = gtk_hseparator_new ();
  gtk_widget_show (hseparator2);
  gtk_fixed_put (GTK_FIXED (fixed1), hseparator2, 0, 48);
  gtk_widget_set_size_request (hseparator2, 529, 17);

  image2 = create_pixmap (install_progressbar, "install-pgb-title.png");
  gtk_widget_show (image2);
  gtk_fixed_put (GTK_FIXED (fixed1), image2, 288, 8);
  gtk_widget_set_size_request (image2, 241, 33);

  image1 = create_pixmap (install_progressbar, "install-pgb-hot.jpg");
  gtk_widget_show (image1);
  gtk_fixed_put (GTK_FIXED (fixed1), image1, 0, 85);
  gtk_widget_set_size_request (image1, 81, 97);

  label_fifo = gtk_label_new ("");
  gtk_widget_show (label_fifo);
  gtk_fixed_put (GTK_FIXED (fixed1), label_fifo, 112, 88);
  gtk_widget_set_size_request (label_fifo, 417, 110);
  gtk_misc_set_alignment (GTK_MISC (label_fifo), 0, 0);

  progressbar2 = gtk_progress_bar_new ();
  gtk_widget_show (progressbar2);
  gtk_fixed_put (GTK_FIXED (fixed1), progressbar2, 112, 272);
  gtk_widget_set_size_request (progressbar2, 417, 25);
  gtk_progress_bar_set_pulse_step (GTK_PROGRESS_BAR (progressbar2), 0.01);

  label1 = gtk_label_new (_("Completed Operations:"));
  gtk_widget_show (label1);
  gtk_fixed_put (GTK_FIXED (fixed1), label1, 112, 328);
  gtk_widget_set_size_request (label1, 417, 25);
  gtk_misc_set_alignment (GTK_MISC (label1), 0, 0);

  label2 = gtk_label_new (_("Current Operation:"));
  gtk_widget_show (label2);
  gtk_fixed_put (GTK_FIXED (fixed1), label2, 112, 248);
  gtk_widget_set_size_request (label2, 417, 25);
  gtk_misc_set_alignment (GTK_MISC (label2), 0, 0);

  g_signal_connect ((gpointer) install_progressbar, "delete_event",
                    G_CALLBACK (gtk_main_quit),
                    NULL);
  g_signal_connect ((gpointer) install_progressbar, "show",
                    G_CALLBACK (on_install_progressbar_show),
                    NULL);
  g_signal_connect ((gpointer) fixed1, "delete_event",
                    G_CALLBACK (gtk_main_quit),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (install_progressbar, install_progressbar, "install_progressbar");
  GLADE_HOOKUP_OBJECT (install_progressbar, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (install_progressbar, progressbar1, "progressbar1");
  GLADE_HOOKUP_OBJECT (install_progressbar, hseparator1, "hseparator1");
  GLADE_HOOKUP_OBJECT (install_progressbar, hseparator2, "hseparator2");
  GLADE_HOOKUP_OBJECT (install_progressbar, image2, "image2");
  GLADE_HOOKUP_OBJECT (install_progressbar, image1, "image1");
  GLADE_HOOKUP_OBJECT (install_progressbar, label_fifo, "label_fifo");
  GLADE_HOOKUP_OBJECT (install_progressbar, progressbar2, "progressbar2");
  GLADE_HOOKUP_OBJECT (install_progressbar, label1, "label1");
  GLADE_HOOKUP_OBJECT (install_progressbar, label2, "label2");

  return install_progressbar;
}

