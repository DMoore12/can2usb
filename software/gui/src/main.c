#include <gtk-3.0/gtk/gtk.h>
#include "main.h"

app_widgets_usr wdgts;          // User widgets
GtkBuilder*     builder;        // Builder instance

int main(int argc, char *argv[])
{
    GtkWidget  *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "glade/mainWindow.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    gtk_builder_connect_signals(builder, NULL);

    //gdk_threads_add_timeout(1000, bgLoop, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    return EXIT_SUCCESS;
}

void initItems()
{
    //wdgts.label_conn_can = GTK_WIDGET(gtk_builder_get_object(builder, "label_conn_can"));
}

static void hardFault(uint8_t type)
{
    // Locals
    GtkDialogFlags flags;
    GtkWidget*     dialog;

    flags = GTK_DIALOG_DESTROY_WITH_PARENT;

    // switch (type)
    // {
    //     case PROCESS_OPEN:
    //         dialog = gtk_message_dialog_new(NULL, flags, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Error: Cannot open GUI with another instance running");
    //         break;

    //     case BAD_HOME:
    //         dialog = gtk_message_dialog_new(NULL, flags, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Error: Improper home directory set");
    //         break;
        
    //     default:
    //         dialog = gtk_message_dialog_new(NULL, flags, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Error: Something went wrong");
    // }

    // gtk_dialog_run (GTK_DIALOG (dialog));
    gtk_widget_destroy (dialog);
}

void on_menuitm_quit_activate(GtkMenuItem *menuitem, app_widgets *app_wdgts)
{
    gtk_main_quit();
}

void on_window_main_destroy(GtkMenuItem *menuitem, app_widgets *app_wdgts)
{
    gtk_main_quit();
}