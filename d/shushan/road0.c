//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","����С·");
  set ("long", @LONG

����һ���ֳ���խ������С·�����������Ĳ�֪�����˼�����,С·��
����������߾�����ѻ��Ĵ�ͷ�ˡ������������ߣ��ϱߵ����ߵ�
����Խ��Խ���ˡ�
LONG);

  set("outdoors", 2);
  set("exits", ([      
 "southwest" : __DIR__"shanlu",
      "east" : __DIR__"exit",
 ]));
 setup();
}






