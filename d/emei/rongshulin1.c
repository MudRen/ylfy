// Room: /d/emei/rongshulin1.c ������


inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������Ե�һ��С·��������ľ������ʮ��ï�ܣ�������Ϊ�ࡣ��
ï��֦Ҷ�ڵ�Ũ��οա����ּ䲻ʱ���Կ����м�ֻ����ӹ���ÿ���峿���
�裬�����ּ�������ֻ�ᳲ��ʱ���ڳ�ϼ�����ĺɫ��ã������з��裬
���������ί���쳹������
LONG
	);

	set("exits", ([
                 "west":__DIR__"jietuopo",
                 "east":__DIR__"rongshulin2",
	]));
        set("outdoors", "emei");
	setup();
}