inherit ROOM;

void create()
{
        set("short", "���᷿");
        set("long", @LONG
һ��СС���᷿�����ǲ��õ�ʮ�����£���������Ů���ӵ���Ʒ��
��������һ��15��6���Ů����ס�����ҡ�ǽ�Ϲ���һ����(picture).
LONG
        );

        set("exits", ([
                "south" : __DIR__"houyuan",
        ]));

        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yangbuhui" : 1,
]));
        set("item_desc", ([
                "picture" : "һ����ͨ�Ĳ�������ͨ�ķ羰����\n",
        ]));
        setup();
}

void init()
{
        add_action("do_pull", "pull");
}


int do_pull(string arg)
{
        object me;

        me = this_player();

        if ( !arg || ( arg != "picture" ) )
       return notify_fail("ʲô��\n");
       message_vision("$N���������һ�»��ĵ��ᣬֻ�������غ�¡һ�죬������һ�����ڡ�\n", me);
         { me->move(__DIR__"ymdrk");
         }

      return 1;
}

