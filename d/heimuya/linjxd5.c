// ROOM : linjxd5.c
inherit ROOM;
void create()
{
  set("short","�ּ�С��");
  set("long",
      "������һ���������ּ�С���ϣ���������ɭɭ�����֡�һ����紵��\n"
      "����, ����ɳɳ������, ���㲻������. ��Ȼ�㷢����������������\n"
      "âһ����û!!\n" );
  set("exits",([
      "southup" : __DIR__"dating1",
      "north" : __DIR__"linjxd4",     
      "east"  : __DIR__"linjxd3",
      "west"  : __DIR__"linjxd5",]));
  set("objects",([
           __DIR__"npc/wolf" : 4 ,]));    
 setup();
 replace_program(ROOM);
}
