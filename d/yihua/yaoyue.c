// ROOM : yaoyue.c
inherit ROOM;
void create()
{
  set("short","���¹�");
  set("long",@LONG
�������¹�����Ϣ�ĵط���ֻ��һ��������, ò���绨��Ů��վ����
������,�������书���,������ص��ƻ�����������ǰ��Ϊ������������
�������ǳ������ˣ��������������ò�Ҫ�ӽ�����
LONG
    );
  set("exits",([
      "west" : __DIR__"changlang1",
      "southwest" : __DIR__"woshi",
     ]));
  set("objects",([
        "/kungfu/class/yihua/yaoyue" : 1,
     ]));
 setup();
 replace_program(ROOM);
}
