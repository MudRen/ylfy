
inherit ROOM;
void create()
{
        set("short", "青石大道");
        set("long", @LONG
来到这里，豁然开朗。一条碎石铺成的大道使这里有点都市的味道。
由于这里远离喧嚣的城镇，环境优美，又由于附近屹立着与外界少有来
往的“血河派”，使这里逐步发展成一个人口聚集的小镇。东边就是一
个约具规模的小镇。
LONG );
        set("valid_startroom",1);
        set("outdoors","龙门");
        set("class","血河派");
        set("exits", ([
                "west"  : __DIR__"qsroad1",
                "east"  : __DIR__"dexit",
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

