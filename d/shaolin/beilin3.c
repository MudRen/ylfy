// Room: /d/shaolin/beilin3.c
// Date: YZC 96/01/19
inherit ROOM;
int do_study(string arg);
void create()
{
    set("short", "������");
    set("long", @LONG
�����Ƿ������µĵ������ҡ�������С��ȴҲ�����ȫ��
ʯ��(table)ʯ�Σ�ʯ��ʯ���������ڷŵļ�������,Ҳ����ʯ
�Ƶġ������ƺ��ܾ���ǰ����������ס�������е�ʯ����ƽ��
��һ�鱡����ʯ�壬����������Щʲô��
LONG
    );
    set("objects",([
        "clone/book/book-stone" : 1,
    ]));
    set("item_desc", ([
        "table" : "����һ�����ʯ��ɵ�ʯ�����������Щ��ֵ�ͼ�Ρ�\n",
    ]));
    setup();
}
void init()
{
    add_action("do_study", "study");
}
int do_study(string arg)
{
    object me;
    int    jing_cost;
    me = this_player();
    if ( !arg || ( arg != "table" ) )
        return 0;
    if ( (int)me->query_skill("literate", 1) < 1){
        write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
        return 1;
    }
    if ( (int)me->query_int() < 30){
        write("������Բ�������ѧ���Ļ�(literate)�ɡ�\n");
        return 1;
    }
    jing_cost = (-1) * random(20);
/*if((int)me->query("jing") < jing_cost){
        write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
        return 1;
}*/
     me->add("jing", jing_cost);
    me->delete_temp("stone_learned");
    message_vision("$N��ר���ж�ʯ���ϵĹŹ�ͼ�Ρ�\n", me);
    switch( random(7) )
    {
        case 0:
        if ( (int)me->query_skill("parry", 1) < 200)
        {
            me->improve_skill("parry", me->query_int());
            write("�����ʯ����ĥ��һ�ض����ƺ��Բ���ж��֮���е��ĵá�\n");
    break;}else {me->set_temp("stone_learned",1);break;
        }
        case 1:
        if ( (int)me->query_skill("unarmed", 1) < 200)
        {
            me->improve_skill("unarmed", me->query_int());
            write("�����ʯ����ĥ��һ�ض����ƺ���ȭ��֮���е��ĵá�\n");
        break;} else {me->set_temp("stone_learned",1);break;
        }
        case 2:
        if ( (int)me->query_skill("sword", 1) < 200)
        {
            me->improve_skill("sword", me->query_int());
            write("�����ʯ����ĥ��һ�ض����ƺ��Ի��������е��ĵá�\n");
    break;} else {me->set_temp("stone_learned",1);break;
        }

        case 3:
        if ( (int)me->query_skill("club", 1) < 200)
        {
            me->improve_skill("club", me->query_int());
            write("�����ʯ����ĥ��һ�ض����ƺ��Թ����е��ĵá�\n");
 break;} else {me->set_temp("stone_learned",1);break;
        }

        case 4:
        if ( (int)me->query_skill("whip", 1) < 200)
        {
            me->improve_skill("whip", me->query_int());
            write("�����ʯ����ĥ��һ�ض����ƺ��Ա޷��е��ĵá�\n");
 break;} else {me->set_temp("stone_learned",1);break;
        }
        default :
            write("�����ʯ����ĥ��һ�ض�,�����˳�˼֮��!\n");break;
    }
    if ( me->query_temp("stone_learned") )
    {
        write("�����ʯ����ĥ��һ�ض�������������˵��̫��ǳ�ԣ�������˵�Ѻ��������ˡ�\n");
    }
    return 1;
}
