// Room in ����
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
��������ʿ�йݵ����ã�������һ���ң���д��һ�����ġ��䡹
�֣����ϲ������£��������ų���������������û�����Σ����Ϸ��ż�
�����š�
LONG);
set("exits", ([
                "out":__DIR__"xingguan"
	]));
   set("objects",([
      "clone/weapon/changjian":3,
      ]));
       setup();
	replace_program(ROOM);
}	
