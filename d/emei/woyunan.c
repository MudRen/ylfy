// Room: /d/emei/woyunan.c ������ ������

inherit ROOM;


void create()
{
	  set("short","������");
      set("long",@LONG
�������Ա��и�����Ȫ����˵��ǰ������ˮ�˶���ɺԣ�����Ϊ֮�о���
����Ȫˮ���������������ֱ��Ƕù�̨���Ա��ǻ����֡�
LONG);

	set("exits", ([
		"northeast" : __DIR__"jinding",
		"southup" : __DIR__"duguangtai",
	]));

	set("objects",([
		"d/emei/npc/girldizi" : 1,
	]));

	setup();
	replace_program(ROOM);
}
