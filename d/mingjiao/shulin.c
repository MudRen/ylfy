inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һƬïʢ�����֣���һ�����ͺ�����ʧ�˷�����������һ���
�أ���������ʮ�ĸ��ߵͲ��ȵ�ľ׮(zhuang)���������а���֮��
�����е������ڴ���ϰ���ա�
LONG
        );

        set("exits", ([
                "east" : __DIR__"jumuqi",
                "west" : __DIR__"shulin1",
        ]));

        set("item_desc", ([
                "zhuang" : "��Щľ׮���ھ���������������Ծ(jump),�����쳣�⻬��\n",
        ]));
        setup();
}

void init()
{
        add_action("do_jump", "jump");
}


int do_jump(string arg)
{
        int xianzhi;
        object me;

        me = this_player();

        if ( !arg || ( arg != "zhuang" ) )
                return notify_fail("ʲô��\n");
        if ( (int)me->query("combat_exp") >0) xianzhi=10;
        if ( (int)me->query("combat_exp") >800) xianzhi=20;
        if ( (int)me->query("combat_exp") >900) xianzhi=30;
        if ( (int)me->query("combat_exp") >6400) xianzhi=40;
        if ( (int)me->query("combat_exp") >12500) xianzhi=50;
        if ( (int)me->query("combat_exp") >21600) xianzhi=60;

        if ( (int)me->query("jing") < 40)
                return notify_fail("���Ѿ����۵��ˣ�����Ϣһ�°ɡ�\n");


        me->add("jing", (-1)*random(40));

        message_vision("$N����Ծ����ľ׮����ľ׮��ߵ����ص���Ծ�š�\n", me);

        if ( (int)me->query_skill("dodge", 1) < xianzhi)
        {
        me->improve_skill("dodge", me->query("int"));
        write("����������Ծ֮�����������ƺ��Ի����Ṧ�е��ĵá�\n");
        me->set_temp("stone_learned",1);
        }
        else
        {
 write("��ƴ����������ȥ��ȴ�о������κν�չ���������㾭\n"
       "�鲻�������Ṧ�Ѿ�������ʮ���ˡ�\n");
        }
        return 1;
}


