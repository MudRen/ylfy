//  /d/emei/zoulang5 ����5
// crate by host dec,15 1997

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���������ȵľ�ͷ����ʯ���̳ɵ�С·�����ߵ����Ӻ����˶�������
�����ɣ������˵�һ����ֲ�����Ļ��ݣ�������Ϊͻ�����Ƕž黨������
������ïʢ�����ҵ�ʮ��������ǰ����һʯ������ľ�Ĵ��Ž����Ĺر��š�
��ʯ���Ϸ�׭�����������֡����޶�����
LONG
	);

	set("exits", ([
		"east" : __DIR__"zoulang4",
                "south" : __DIR__"qingxiudong",
	]));

	setup();
}


