//room: /d/btshan/zhailou.c
inherit ROOM;
void create()
{
  set("short","Сլ��");
  set("long",
      "������һ����Ӱ��涵ľ��׵�Сլ�䣬���з���һ���ںڷ����Ĵ�\n"
  "ˮ�ס�����ɽ�ϳ����ѩ����������˼���һ����������������������\n"
  "ѩˮ�������е�ˮ��������\n"
     );
  set("exits",([
      "west" : __DIR__"liangong",
     ]));
  set("outdoors", "baituo");
  set("resource/water", 1);
 setup();
 replace_program(ROOM);
}
