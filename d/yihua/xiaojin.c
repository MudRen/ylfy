//room: xianchou.c
inherit ROOM;

void create()
{
  set("short","С��");
  set("long",@LONG
�㻬��ȵ�,ͻȻһ����������,ʹ����������,�ƺ���������
ò�绨��Ů��վ��·��,�㲻����������ʹ.����ǰ��ȥ֮����
�ʻ������ƺ������Ǳ�!
LONG
     );
  set("outdoors", "yihua");
  set("exits",([
      "south" : __DIR__"yihua_in",
      "up" : __DIR__"juebi",
     ]));

 setup();
 replace_program(ROOM);
}