// Room: /d/dali/guangchang.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��19�գ�����ʱ�䣺21ʱ28��14�롣

inherit ROOM;

void create()
{
	set("short", "���������");
	set("long", @LONG
������Ǵ���ǵĳ����ģ�����ǵ���Ҫ�ֵ��������ｻ�ᣬ����·��������
�γ���һ����԰Լʮ���ɵĹ㳡���㳡�����Σ�һȦΧ�Ķ���С�������ˣ��Ϳ�����
�ġ�������������Ⱥ��Ҳ�ٲ���Щ���ܽ����ģ���ˣ��������������˷���һЩ����
ԭ����δ�ŵ�����������һЩ���뽭�����������˷ܲ��ѡ�λ�ڹ㳡������һ������
��С��ˮ�أ�һ�޴������ʯ������ˮ�����룬һ����ĸ�Ȫˮ��ʯ����������ӿ����
������ʯ���Ͽ�ȥ��ֻ�����飺

                          [1;33m~   ��  ��  ~[2;37;0m

                          [1;33m~   ��  ��  ~[2;37;0m

                          [1;33m~   ̫  ��  ~[2;37;0m

                          [1;33m~   ƽ  ��  ~[2;37;0m

LONG
	);
	set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"paifang",
  "west" : __DIR__"xidajie1",
  "east" : __DIR__"dongdajie1",
  "south" : __DIR__"nandajie1",
]));

        set("objects", ([
                __DIR__"npc/dlxunbu" : 2,
                __DIR__"npc/liumangtou" : 1,
                __DIR__"npc/liumang" : 2,
        ]));
	setup();
        "/clone/board/dali_b"->foo();
}
