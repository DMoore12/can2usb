#ifndef _MAIN_H_
#define _MAIN_H_

// Inlcudes
#include <stdlib.h>
#include <stdint.h>
#include "ui.h"

// Enumerations
typedef enum {
    // MAIN_CNT must come last!
    MAIN_CNT                            // Number of main page widgets
} main_page_t;

typedef enum {
    // CONN_CNT must come last!
    CONN_CNT                            // Number of connection page widgets
} connection_page_t;

typedef enum {
    HFAULT_GENERIC = 0,                 // Generic, hard fault
    // HFAULT_CNT must come last!
    HFAULT_CNT                          // Number of hard faults
} hard_fault_reason_t;

// Structures
typedef struct {
    GtkWidget*     w_txtvw_main;        // Pointer to text view object
    GtkWidget*     w_dlg_file_choose;   // Pointer to file chooser dialog box
    GtkTextBuffer* textbuffer_main;     // Pointer to text buffer
} app_widgets;

typedef struct {
    GtkWidget* main[MAIN_CNT];          // Pointers to main page widgets
    GtkWidget* connect[CONN_CNT];       // Pointers to connection page widgets
} app_widgets_usr;

// Function prototypes
static void hardFault(uint8_t type);
void on_menuitm_quit_activate(GtkMenuItem *menuitem, app_widgets *app_wdgts);
void on_window_main_destroy(GtkMenuItem *menuitem, app_widgets *app_wdgts);

#endif