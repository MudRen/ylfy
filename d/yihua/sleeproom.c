//room: sleeproom.c
//sleeproom
inherit ROOM;

void create()
{
  set("short","õ���");
  set("long",@LONG
�������ƻ�������˯���ĵط���һ���ž��ŵ�һ�����Ƶ���������ϸһ��
�ŷ�������Ĵ�ȫ�����ʻ����ɣ��㲻�ɵ��������������Ĺ��˵����ռ�ֱ
���ɶ��칤��
LONG
     );

  set("exits",([
      "west" : __DIR__"yihua_ge",
     ]));

  set("sleep_room", 1);
  set("no_fight",1);
  set("no_steal",1);

 setup();
 replace_program(ROOM);
}
