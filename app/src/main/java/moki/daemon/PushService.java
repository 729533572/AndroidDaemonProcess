package moki.daemon;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;

public class PushService extends Service {
    static {
        System.loadLibrary("daemon");
    }

    public PushService() {
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        startDaemonProcess();
        return super.onStartCommand(intent, flags, startId);
    }

    @Override
    public IBinder onBind(Intent intent) {

        // TODO: Return the communication channel to the service.
        throw new UnsupportedOperationException("Not yet implemented");
    }

    public static native void startDaemonProcess();
}
