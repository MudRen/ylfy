//  /d/emei/zoulang4 ����4
// crate by host dec,15 1997

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
��������һ�������ϡ���ʯ���̳ɵ�С·�����ߵ����Ӻ����˶�������
�����ɣ������˵�һ����ֲ�����Ļ��ݣ�������Ϊͻ�����Ƕž黨������
������ïʢ�����ҵ�ʮ��������
LONG
	);

	set("exits", ([
		"west" : __DIR__"zoulang5",
		"north" : __DIR__"zoulang2",
	]));

	setup();
}


