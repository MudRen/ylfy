// Room: /d/emei/baoguosi.c ������ ������


inherit ROOM;


void create()
{
        set("short", "������");
	set("long", @LONG
�����Ƕ��ҵ�ɽ�µı����£���ǰϪˮ���������ڹ�ľ���죬������
�����º�һ�����ֻͨ����ɽɽ�ţ����±ߴ���һ���޴��ʯ��������׭
���š����Ͼ���ȫ�ġ������Ǳ����µĴ�������һ������������һ��
С·ֱͨһƬ���֡�
LONG
	);

	set("exits", ([
                "east":__DIR__"chanfang",
                "south": __DIR__"baoguosi1",
                "southwest":__DIR__"milin1",
                "northdown":__DIR__"shanmen",
	]));
        set("objects",([
	 "/d/emei/npc/xiang-ke" : 2,]));

	setup();
}
