// Room: /d/emei/fushouan.c ������ ������

inherit ROOM;

void create()
{
	 set("short","������");
      set("long",@LONG
����������ˮ���ϣ���һ���������Ե�ɮ�˽���ġ���ǰ�о�����������
�أ����������ڴ������������۾���ʫ����ӽ��̾����֪Ϧ�ա����������
���������ٲ��䣬�ߴ�ʮ���ɡ�
LONG);

	set("exits", ([
		"northdown" : __DIR__"shenshuige",
		"east" : __DIR__"lingwenge",
	]));

	set("objects",([		
		"d/emei/npc/girldizi" : 1,
	]));
	
	setup();
	replace_program(ROOM);	
}
