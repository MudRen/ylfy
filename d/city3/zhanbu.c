//bye enter

inherit ROOM;

void create()
{
	set("short", "ռ������");
	set("long", @LONG
�ſڹ���һ������(sign),�����Ե���Щ�տյ�����,Ϲ����
������һ�ź���ķ�����,��������һ�Űײ�,�������һͲ����
�õ���ǩ�ͼ�öͭǮ������ǰ��һ�Ź��������ĵ��ӡ�
LONG
	);

	set("exits", ([
                "south" : __DIR__"xijie1",
	]));

	set("item_desc",([
                 "sign": "���㲻�����㣬���㲻�����㡣\n",
                    ]));
        set("objects" ,([
                 __DIR__"obj/chair" : 1,
                    ]));

	setup();
	replace_program(ROOM);
}

