import java.applet.*;
<html>
<applet code="SimpleApplet.class" width="800" hight="600">
</applet>
</html>
class SimpleApplet extends Applet {
    String msg;
    public void init() {
        msg="Inside init()";
    }
    public void start() {
        msg=msg+" Inside start()";
    }
    public void paint(Graphics g) {
        msg=msg+" Inside paint()";
        g.drawString(msg,100,100);//x=100 y=100
    }
    public void stop() {
        msg=msg+" Inside stop()";
    }
    public void destroy() {
        msg=msg+" Inside destroy()";
    }
}