// ROOM : lianxin.c
inherit ROOM;
void create()
{
  set("short","���ǹ�");
  set("long",@LONG
�������¹�����Ϣ�ĵط���ֻ��һ��������,ò���绨��Ů��վ����
������,�������书���,������ص��ƻ�����������ǰ��Ϊ���Ľ������
�����������������������ǳ������ˣ��������������ò�Ҫ�ӽ�����
LONG
    );
  set("exits",([
      "east" : __DIR__"changlang1",
      "southeast" : __DIR__"woshi",
     ]));
  set("objects",([
"/kungfu/class/yihua/lianxing" : 1,	
     ]));
 setup();
 replace_program(ROOM);
}
