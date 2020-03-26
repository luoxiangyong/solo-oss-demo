#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

int main(int argn, char** argv)
{
  QApplication app(argn,argv);

  QMainWindow mainWindow;

  mainWindow.setWindowTitle("我的测试！");
  mainWindow.resize(800,600);
  mainWindow.show();

  return app.exec();

}
