// ROOM : linjxd1.c
inherit ROOM;
void create()
{
  set("short","�ּ�С��");
  set("long",
      "������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ����紵��\n"
      "����, ����ɳɳ������, ���㲻������.�������ߺ�����һ��ɽ�ȡ� \n"
     );
  set("exits",([
      "south" : __DIR__"linjxd2",
      "north" : __DIR__"linjxd5",     
      "east"  : __DIR__"road1",
      "west"  : __DIR__"guang",
         
  ]));
 setup();
 replace_program(ROOM);
}
