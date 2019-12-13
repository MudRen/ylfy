inherit F_CLEAN_UP;
int main(object me)
{
        
        mapping info;
        float x, fraction;
        string str;
        info = rusage();
        x = info["utime"] + info["stime"];
        // time is in msec, convert to sec
        x = (info["utime"] + info["stime"])/1000;
        fraction = x / uptime();    
        str = sprintf("CPU usage: %2.2f%%\n", fraction * 100);
        write( str );
        write("使用者时间 = " + info["utime"] + "微秒\n");
        write("系统时间 = " + info["stime"] + "微秒\n");

        return 1;
}
