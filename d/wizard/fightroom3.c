// Room: /d/wizard/fightroom3.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "��̨");
    set("long", @LONG
����! ����! ����! ����! ����! ����! ����! ����! ����! ����! 
LONG
    );
    set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"fightroom2",
]));
    set("no_new_clean_up", 0);
	set("no_fly", 1);
    set("fight_room", __DIR__"fightroom2");
   set("no_sleep_room",1);
    setup();
}
void relay_message(string msg)
{
    object look_fight_room;
   string *msgs;
    int i;
    if (!look_fight_room=find_object("/d/wizard/fightroom2"))
    look_fight_room=load_object("/d/wizard/fightroom2");
   msgs=explode(msg, "\n");
    for (i=0;i<sizeof(msgs);i++)
    if (strlen(msgs[i])>5)
    message("vision",NOR+"@@ -->"+msgs[i]+"\n",look_fight_room);
}
int valid_leave(object me, string dir)
{
   if (me->is_fighting() && dir=="down")
	return notify_fail("�������ӣ��Ǵ��ɷ���Ϊѽ��\n");
         return ::valid_leave(me, dir);
}
