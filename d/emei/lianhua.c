// /d/emei/lianhua.c ������ ������
// create by host dec,12

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ƕ��ҵ��з壬�����塣�����������Ϊƽ������������ɽ���
�վ�����������СС������Ǿ����������ˡ������Ͼ��Ƕ��ҵ���߶���
������ϡϡ������ʮ���䷿�ӣ��Ƕ����ɵĵط��������ο���ñ�������
ȥ��
LONG
	);
        set("outdoors", "emei");
	set("exits", ([ 
                "northdown":__DIR__"shijie2",
                "southup": __DIR__"shijie3",
                "west" : __DIR__"wanxingan",
		]));
	set("objects", ([ 
	]));

	setup();
}
