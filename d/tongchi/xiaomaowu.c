inherit ROOM;
void create()
{
          set("short", "小茅屋");
        set("long", @LONG
小茅屋，屋顶茅草；巳被雨洗刷得泛白，古旧腐蚀不堪，屋前有一排栏
杆，田字窗。门前右上方，挂着一块匾仔细一看，字体歪歪斜斜，共写有
「通吃小  」四字，刻划甚新，必是新造之物。而这些字，说它像乌龟爬
的，亦不为过，就像老鼠用尾巴沾上墨汁在桌上打转所留下来似的，怪里
怪气，无法想像。
LONG
        );
        set("exits", ([
                   "east" : __DIR__"tingyuan",
        ]));
        set("objects", ([
        ]));
        setup();
        replace_program(ROOM);
}
