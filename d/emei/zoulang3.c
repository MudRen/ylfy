//  /d/emei/zoulang3 ����3
// crate by host dec,15

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����ǳ��ȵľ�ͷ���ڱ�����һ�����������͵����ӣ�ʮ�ֵ����ţ�����
���ڡ���ϸ������������������ż������������Ц�����ߵ���ǰ�������Բ�ʱ
���ŵ�������Ʈ������Ũ����������
LONG
	);

	set("exits", ([
		"west" : __DIR__"zoulang1",
		"north" : __DIR__"chufang",
	]));

	setup();
}


