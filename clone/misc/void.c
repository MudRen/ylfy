// Room: /clone/misc/void.c
inherit ROOM;

void create()
{
	set("short", "������԰");
	set("long", @LONG
������Ǵ�˵�е� VOID -- �������ʦ��������԰. �㿴������һƬ
��ãã��, ��һ���������ð��һֻ���, �ݸ���һ�ޡ��ɿڿ��֡�(tm), 
Ȼ��վ��һ�Ժ�а���Ц��. �ֹ���һ��, һֻ���������˹���, һ���ı�
����ֻ��첢��������������ƿ����, ��Ц������ʹ�����ǰ��ʧ��.
��ҡҡͷ, ���ֵط����ǲ�Ҫ��̫�õĺ�.
LONG
);
	set("no_new_clean_up", 0);
	set("no_magic", 1);
	set("no_fight", 1);
	set("exits", ([
		"down" : "/d/city/zuixianlou",
		]));

	setup();
	replace_program(ROOM);
}
