// Room: /d/wizard/fightroom1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "���䳡����");
    set("long", @LONG
��������վ������������ڣ���ֻ�޴��ʯʨ�����ڴ��ŵ����࣬������
��·���ֺú��������յ���̨����ʱ���������ཻ��������ͨ��������������
�ִ�᳡�ĳ��ڡ�
LONG
    );
    set("no_new_clean_up", 0);
    set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"fightroom2",
  "south" : __DIR__"fightroom4",
]));
    setup();
}
int valid_leave(object me, string dir)
{
    mixed *local;
    local=localtime(time());
//     if ( dir=="east" && (local[6]==6 || local[6]==0) )
//      return notify_fail("������䳡������!\n");
          if (!userp(me) && dir=="east")         return 0;
      return ::valid_leave(me, dir);
}
