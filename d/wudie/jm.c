// Room: /d/wudie/jm.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
	set("short", "景门");
	set("long", @LONG
这里去碟舞山庄的必经之路，群山尽收眼底，白云在你的脚下缭
绕。只有一条铺着鹅卵石的小径向前伸延，小路两旁是一排茂密的松
林。走在小路上，给人一种心旷神怡的感觉。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"southdown" : __DIR__"shanlu40",
		"north" : __DIR__"qjm",
	]));
	set("no_clean_up", 0);
	set("objects", ([
        __DIR__"npc/diefeng" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
    object ob=present("die feng", environment(me));
    if ((me->query("family/family_name") != "舞蝶仙") && dir == "north" &&
                objectp(ob) && living(ob) )
       return notify_fail("碟凤拦住你说道：你不是舞蝶仙弟子，\n此去多有不便，请留步。\n如果入门先拜我\n");
        
        return ::valid_leave(me, dir);
}
