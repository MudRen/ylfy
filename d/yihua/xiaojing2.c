//room: xiaojing2.c
inherit ROOM;

void create()
{
  set("short","С��");
  set("long",@LONG
ͻȻһ����������������,��˳��������ȥ�������
Ȼ��һƬ�����أ������������󣡵��ϳ������ʻ���ʮ��
����!
LONG
     );
  set("outdoors", "yihua");
  set("exits",([
      "east" : __DIR__"midao_out",
      "west" : __DIR__"lianhuachi",
     ]));

 setup();
 replace_program(ROOM);
}