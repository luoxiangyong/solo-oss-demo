#include <QtCore/QApplication>
#include <QtWidget/QMainWindow>

int main(int argn, char** argc)
{
  QApplication app = QApplication(argn,argv);

  QMainWindow mainWindow = QMainWindow();

  mainWindow.setTitle("我的测试！");
  mainWindow.show();

  return app.exec();

}
