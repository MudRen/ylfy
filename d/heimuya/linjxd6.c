// ROOM : linjxd6.c
inherit ROOM;
void create()
{
  set("short","�ּ�С��");
  set("long",
      "������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ����紵��\n"
      "����, ����ɳɳ������, ���㲻������. \n"
     );
  set("exits",([
      "south" : __DIR__"linjxd1",
      "north" : __DIR__"linjxd4",     
      "east"  : __DIR__"up1",
      "west"  : __DIR__"dating2",
     ]));
 setup();
 replace_program(ROOM);
}
