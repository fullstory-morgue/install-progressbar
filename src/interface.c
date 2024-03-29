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
  GtkWidget *progressbar2;
  GtkWidget *image3;
  GtkWidget *hseparator1;
  GtkWidget *label2;
  GtkWidget *label_fifo;
  GtkWidget *hseparator2;
  GtkWidget *image2;
  GtkWidget *label1;
  GtkWidget *label_clock;
  GtkWidget *scrolledwindow1;
  GtkWidget *viewport1;
  GtkWidget *fixed2;
  GtkWidget *label_generally;

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
  gtk_fixed_put (GTK_FIXED (fixed1), progressbar1, 0, 448);
  gtk_widget_set_size_request (progressbar1, 600, 24);
  gtk_progress_bar_set_pulse_step (GTK_PROGRESS_BAR (progressbar1), 0.01);

  progressbar2 = gtk_progress_bar_new ();
  gtk_widget_show (progressbar2);
  gtk_fixed_put (GTK_FIXED (fixed1), progressbar2, 0, 376);
  gtk_widget_set_size_request (progressbar2, 600, 25);
  gtk_progress_bar_set_pulse_step (GTK_PROGRESS_BAR (progressbar2), 0.01);

  image3 = create_pixmap (install_progressbar, "install-pgb-hot.jpg");
  gtk_widget_show (image3);
  gtk_fixed_put (GTK_FIXED (fixed1), image3, 8, 0);
  gtk_widget_set_size_request (image3, 88, 80);
  gtk_misc_set_alignment (GTK_MISC (image3), 0, 0);

  hseparator1 = gtk_hseparator_new ();
  gtk_widget_show (hseparator1);
  gtk_fixed_put (GTK_FIXED (fixed1), hseparator1, 0, 312);
  gtk_widget_set_size_request (hseparator1, 600, 17);

  label2 = gtk_label_new (_("Current\nOperation:"));
  gtk_widget_show (label2);
  gtk_fixed_put (GTK_FIXED (fixed1), label2, 0, 336);
  gtk_widget_set_size_request (label2, 129, 41);
  gtk_label_set_line_wrap (GTK_LABEL (label2), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label2), 0, 0);

  label_fifo = gtk_label_new ("");
  gtk_widget_show (label_fifo);
  gtk_fixed_put (GTK_FIXED (fixed1), label_fifo, 104, 336);
  gtk_widget_set_size_request (label_fifo, 494, 41);
  gtk_label_set_line_wrap (GTK_LABEL (label_fifo), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label_fifo), 0, 0);

  hseparator2 = gtk_hseparator_new ();
  gtk_widget_show (hseparator2);
  gtk_fixed_put (GTK_FIXED (fixed1), hseparator2, 0, 88);
  gtk_widget_set_size_request (hseparator2, 600, 17);

  image2 = create_pixmap (install_progressbar, "install-pgb-title.png");
  gtk_widget_show (image2);
  gtk_fixed_put (GTK_FIXED (fixed1), image2, 344, 48);
  gtk_widget_set_size_request (image2, 241, 33);

  label1 = gtk_label_new (_("Completed Operations:"));
  gtk_widget_show (label1);
  gtk_fixed_put (GTK_FIXED (fixed1), label1, 0, 424);
  gtk_widget_set_size_request (label1, 265, 25);
  gtk_misc_set_alignment (GTK_MISC (label1), 0, 0);

  label_clock = gtk_label_new (_("00:00:00"));
  gtk_widget_show (label_clock);
  gtk_fixed_put (GTK_FIXED (fixed1), label_clock, 256, 424);
  gtk_widget_set_size_request (label_clock, 217, 25);
  gtk_misc_set_alignment (GTK_MISC (label_clock), 0, 0);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow1);
  gtk_fixed_put (GTK_FIXED (fixed1), scrolledwindow1, 0, 104);
  gtk_widget_set_size_request (scrolledwindow1, 601, 209);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow1), GTK_SHADOW_IN);

  viewport1 = gtk_viewport_new (NULL, NULL);
  gtk_widget_show (viewport1);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), viewport1);

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (viewport1), fixed2);

  label_generally = gtk_label_new (_("<span foreground=\"indianred4\" font_desc=\"Sans Bold 14\">What is sidux? - Debian Hot and Spicy!</span>\n\n<span font_desc=\"12\"><b>sidux</b> is a full featured Debian Sid based live CD with a special focus on hard disk installations, a clean upgrade path within Sid and additional hard- and software support.\nThe ISO is completely based on Debian Sid, enriched and stabilized with sidux' own packages and scripts.</span>\n\n\n<span font_desc=\"11\"><b><u>Hints for hardware with non-free needs:</u></b>\n\nsidux contains <b>only dfsg free software</b>, so you'll probably want to add <b>contrib/ non-free </b>to your <b>/etc/apt/sources.list</b> and ensure internet access.\n\n<span foreground=\"darkblue\" font_desc=\"Sans Bold 11\">You can add contrib and non-free with metapackage-installer.</span>\n\n\n<b><u>firmware</u></b>\n\n<span foreground=\"darkblue\" font_desc=\"Sans Bold 11\">* ATi Radeon graphics:</span> 3d acceleration for older cards up to r35x should work, newer Radeon X1xxx cards need non-free drivers for accelerated performance, type '<b>sgfxi -N radeon</b>'\n<span foreground=\"darkblue\" font_desc=\"Sans Bold 11\">* Nvidia  graphics:</span> type '<b>sgfxi -h</b>' to see available options\n* Atheros/ \"madwifi\" wlan: m-a a-i madwifi.\n* Atmel AT76c50x 11 MBit/s wlan: apt-get install atmel-firmware\n* AVM ISDN/ ADSL PCI/ USB Karten: AVM's closed source driver are not compatible with kernel 2.6.20 yet.\n* Broadcom/ bcm43xx wlan: apt-get install bcm43xx-fwcutter.\n* Eagle USB ADSL modem: fetch the firmware from http://eagle-usb.org/ueagle-atm/non-free/ and place it under /lib/firmware/.\n* DVB firmwares for various full featured DVB TV cards (most budget cards won't need this): fetch the needed firmware (check dmesg) from http://www.linuxtv.org/downloads/firmware/ and place it under /lib/firmware/.\n* hostap based 11 MBit/s wlan with loadable firmware (e.g. D-Link DWL-520 rev. E1 and others): http://www.oakcourt.dyndns.org/~andrew/dwl520e1.html\n* Intel ipw2100, 11 MBit/s wlan: fetch the firmware from http://ipw2100.sf.net/ and place it under /lib/firmware/.\n* Intel ipw2200, 54 MBit/s wlan: fetch the firmware from http://ipw2200.sf.net/ and place it under /lib/firmware/.\n* Intel ipw3945, 54 Mbit/s wlan: apt-get install ipw3945d firmware-ipw3945\n* Intersil prism54, 54 MBit/s wlan: fetch the firmware from http://prism54.org/firmware/ and place it under /lib/firmware/.\n* RaLink rt61 54 MBit/s wlan, fetch the firmware from http://www.ralinktech.com/ralink/Home/Support/Linux.html\n* Texas Instruments ACX100 (22 Mbit/s)/ ACX111 (54 MBit/s) wlan, fetch the firmware from http://www.kazer.org/acx-firmware-20060207.tar.bz2 and place it under /lib/firmware/.\n* ZyDAS zd1201 11 MBit/s wlan: apt-get install zd1201-firmware\n* ZyDAS zd1211 54 MBit/s wlan: fetch the firmware from http://sourceforge.net/project/showfiles.php?group_id=129083 and place it under /lib/firmware/.\n* We will check if we can provide packages for at least some of these devices, but the legal status isn't necessarily easy.\n\n\n<b><u>Disclaimer:</u></b>\n\nThis is experimental software. Use at your own risk. The sidux project, it's developers and team members (all represented by the sidux Foundation, Inc) cannot be held liable under any circumstances for damage to hardware or software, lost data, or other direct or indirect damage resulting from the use of this software. If you do not agree to these terms and conditions, you are not permitted to use or further distribute this software.\n\n\n<b><u>Special thanks go to the entire sidux development team:</u></b>\n\nJoaquim Boura (x-un-i)\nRoland Engert (RoEn)\nAedan Kelly (etorix)\nBernard Gray (cleary)\nAndreas Hausmann (Bodhi)\nChris Hildebrandt (slam)\nRalph Hokanson Jr. (piper)\nHarald Hope (h2)\nKel Modderman (kelmo)\nStefan Lippers-Hollmann (slh)\nFerdi Thommes (devil)\nHorst Tritremmel (hjt)\nNiall Walsh (bfree)\nTrevor Walkley (bluewater)\nAndreas Weber (webera)\nand many more\n\na big thank you goes to the documentation and translation teams!\n\nThanks to all involved for making this possible:\n     Stefan Lippers-Hollmann (slh) \n</span>\n"));
  gtk_widget_show (label_generally);
  gtk_fixed_put (GTK_FIXED (fixed2), label_generally, 8, 8);
  gtk_widget_set_size_request (label_generally, 560, 1600);
  gtk_label_set_use_markup (GTK_LABEL (label_generally), TRUE);
  gtk_label_set_line_wrap (GTK_LABEL (label_generally), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label_generally), 0, 0);

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
  GLADE_HOOKUP_OBJECT (install_progressbar, progressbar2, "progressbar2");
  GLADE_HOOKUP_OBJECT (install_progressbar, image3, "image3");
  GLADE_HOOKUP_OBJECT (install_progressbar, hseparator1, "hseparator1");
  GLADE_HOOKUP_OBJECT (install_progressbar, label2, "label2");
  GLADE_HOOKUP_OBJECT (install_progressbar, label_fifo, "label_fifo");
  GLADE_HOOKUP_OBJECT (install_progressbar, hseparator2, "hseparator2");
  GLADE_HOOKUP_OBJECT (install_progressbar, image2, "image2");
  GLADE_HOOKUP_OBJECT (install_progressbar, label1, "label1");
  GLADE_HOOKUP_OBJECT (install_progressbar, label_clock, "label_clock");
  GLADE_HOOKUP_OBJECT (install_progressbar, scrolledwindow1, "scrolledwindow1");
  GLADE_HOOKUP_OBJECT (install_progressbar, viewport1, "viewport1");
  GLADE_HOOKUP_OBJECT (install_progressbar, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (install_progressbar, label_generally, "label_generally");

  return install_progressbar;
}

