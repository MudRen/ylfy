// Room: /d/emei/huayanding.c ������ ���϶�
// create by host dec,20 1997

inherit ROOM;


void create()
{
	set("short", "���϶�");
	set("long", @LONG
����һ���ȽϿ����Ĺ㳡�����ܴ�ݲ������ڹ㳡�м���һ���ɸߵ�Բ
�ν�̳����ʯ̳����һ��ʯ�������߸���һ��ʯ�裬�������졣������ÿ��
�����ڵ��Ӷ�Ҫ��������������˵�������л�Ե���ҵ�����Ҳ��������ָ��
�书��
LONG
	);

	set("exits", ([
                "southeast" : __DIR__"guanyintang",
                "westdown": __DIR__"shierpan4",
	]));

	set("objects",([
	]));

	setup();
	
}
