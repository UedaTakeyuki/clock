// https://qiita.com/code2545Light/items/cda2e787ef6297022112
#include <gtk/gtk.h>

static void destroy(GtkWidget *window, gpointer data)
{
    /*  メインループを終了  */
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    GtkWidget *window, *label;

    /*  GTK+ の初期化  */
    gtk_init(&argc, &argv);

    /*  ウィンドウ(GtkWindow) の作成  */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    /*  ウィンドウの初期設定  */
    gtk_window_set_title(GTK_WINDOW(window), "SKKS");  //  title
    gtk_widget_set_size_request(window, 200, 100);      //  window size

    /*  ウィンドウが消去されたときのコールバック関数を設定  */
    g_signal_connect(G_OBJECT(window), "destroy",
                     G_CALLBACK(destroy), NULL);

    /*  ラベル(GtkLabel) の作成  */
    label = gtk_label_new("Hello, SKKS!");

    /*  ラベルをウィンドウに追加  */
    gtk_container_add(GTK_CONTAINER(window), label);

    /*  ウィンドウを表示  */
    gtk_widget_show_all(window);

    /*  メインループ  */
    gtk_main();

    return 0;
}
