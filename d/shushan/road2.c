//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","��·");
  set ("long", @LONG

    ����һ�����е�ʯ��·��·����һ�ҵ��̣�·������һ��С����Ϸ���
һ�ҾƵ꣬�������߾�Ҫ����ͷ�ˡ�
LONG);

  set("outdoors", 2);
  set("exits", ([      
     "north" : __DIR__"road1",
 "southwest" : __DIR__"road3",
 "southeast" : __DIR__"jiudian",
      "east" : __DIR__"xiaoxiang",
      "west" : __DIR__"dangpu",
 ]));
 setup();
}






