// Room: /d/shaolin/damodong.c
// Date: YZC 96/01/19
inherit ROOM;
void create()
{
    set("short", "��Ħ��");
    set("long", @LONG
�����Ǵ�Ħ�Ŷ��������ǰ������ɮ�������Ħ���������£���
�˷�ˮ���أ���ס�������޵��ӣ��������ڣ����������·������ǧ
�겻��֮������Ħ��ʦ���ڴ���������һ��ʮ�꣬�ڼ��������Կ�
���������ʱ�Ĵ�����̬�������ϵļ�����Ƭ�⣬���п���һ�
LONG
    );
    set("exits", ([
        "out" : __DIR__"qfdian",
    ]));
    set("objects",([
        "clone/book/book-bamboo" : 1,
        CLASS_D("shaolin") + "/damo" : 1,
    ]));
    setup();
}
void init()
{
    object me = this_player();
    if ((int)me->query_temp("bamboo/count") == 14 
    &&  (int)me->query_skill("dodge", 1) >= 30 
    &&  (int)me->query_skill("dodge", 1) <= 100 
    &&  present("bamboo", me) )
    {
        me->receive_damage("jing", 20);
        me->improve_skill("dodge", me->query_int());
        me->delete_temp("bamboo/count");
    }
        add_action("do_mianbi","���"); 
        add_action("do_mianbi","mianbi");   
}
int do_mianbi()
{
    object me = this_player();
    int buddhism=me->query_skill("buddhism");
    if (me->is_busy()) return notify_fail("������Ŵ�Ħ�����ߵ�ʯ�ڵ�����˼......\n");
    if (me->is_fighting()) return notify_fail("�����������������ô��\n");
    if (buddhism>200)
    message_vision("$N����Ŵ�Ħ�����ߵ�ʯ�ڵ�����˼�����ã���������\n", me);
    else{
    message_vision("$N����Ŵ�Ħ�����ߵ�ʯ�ڵ�����˼�����ã��۵�������ʹ��\n", me);
    return 1;
    }
    
    me->start_busy(3);
   if (me->query("shen")>0){
    if (me->query("shen")-buddhism*2<0)
    me->set("shen",0);
    else
    me->add("shen",-buddhism*2);
  }else{
    if (me->query("shen")+buddhism*2<0)
    me->set("shen",0);
    else
    me->add("shen",buddhism*2);
  }
    return 1;
}

