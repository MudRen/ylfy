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
		"east" : __DIR__"guangchang",
		"south" : __DIR__"zoulang4",
	]));

	setup();
}


