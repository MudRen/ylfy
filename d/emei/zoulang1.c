//  /d/emei/zoulang1 ����1
// crate by host dec,15

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����ȡ���ʯ���̳ɵ�С·�����ߵ����Ӻ����˶�����������
�ɣ������˵�һ����ֲ�����Ļ��ݣ�������Ϊͻ�����Ƕž黨��������
����ïʢ�����ҵ�ʮ��������
LONG
	);

	set("exits", ([
		"west" : __DIR__"guangchang",
		"east" : __DIR__"zoulang3",
	]));

	setup();
}


