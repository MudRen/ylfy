// Room: /d/shaolin/guangchang2.c
// Date: YZC 96/01/19
inherit ROOM;
void create()
{
    set("short", "广场");
    set("long", @LONG
过了天王殿，又有三道平行的青石台阶引正前方的一个大广
场。台阶上刻的是诸天众佛，五百罗汉以及三千伽蓝的坐像。上
了平台，正中方也有个丈许高的大香炉，香炉前的香台上，红烛
高烧，香烟飘绕，几位香客正对大殿虔诚叩拜。左右各通向一个
小院，两座高塔高耸天际。正前方就是大雄宝殿。
LONG
    );
    set("exits", ([
        "south" : __DIR__"twdian",
        "north" : __DIR__"guangchang3",
        "northup" : __DIR__"dxbdian",
        "east" : __DIR__"zhonglou",
        "west" : __DIR__"gulou",
    ]));
    set("outdoors", "shaolin");
    set("objects",([
        __DIR__"npc/xiang-ke" : 1,
        __DIR__"npc/seng-bing3" : 2,
        CLASS_D("shaolin") + "/qing-shan" : 1,
    ]));
    setup();
}
void init()
{
    object me=this_player();
    object ob=present("yingxiong ling",me);
    mapping myfam;
    myfam = (mapping)me->query("family");
    if (myfam)
    if (myfam["family_name"] == "少林派" && me->query("gender")=="男性") return;
    if (!ob)
    if (userp(me)){
            tell_object(me, HIY "几个僧兵对你喝道：施主未经我寺邀请，如何进来的？莫非是鼠辈？\n"+"只觉一阵腾云驾雾般，你昏昏沉沉地被扔出了少林寺！\n" NOR);
            me->move("/d/nanyang/shanmen");
            message("vision",
                HIY "只听乒地一声，你吓了一跳，定睛一看，\n"
                "原来是一个昏昏沉沉的家伙从少林寺里被扔了出来！\n" NOR, environment(me), me);
    }
}
