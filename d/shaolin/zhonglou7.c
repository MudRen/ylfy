// Room: /d/shaolin/zhonglou7.c
// Date: YZC 96/01/19
inherit ROOM;
string look_bell();
string look_out();
void create()
{
    set("short", "��¥�߲�");
    set("long", @LONG
���������¥֮����ֱ�������ı����ǿڴ��Ӻ�һ�����ҿ�
�еľ��ơ�ϸ�����ӣ��������������ߣ�ֱ��Ҳ������������
����ͭ�����������������������ӡ�Ĺ�׭������������ǧ�
���ƴֿɺϱ����ɰ�������һͷ���Ժ�Ƥ������������������ɽ
�紵��������˭������ס��ײһ����(bell)���ԡ����⿴���и���
��ĺ�����̨(window)���������վһ����,������벻���Ļ���
������һ����¥(tiao lou)��
LONG
    );
    set("exits", ([
        "down" : __DIR__"zhonglou6",
    ]));
    set("item_desc",([
        "bell"      :   (: look_bell :),
        "out"       :   (: look_out :),
    ]));
    set("objects",([
        CLASS_D("shaolin") + "/qing-xiao" : 1,
    ]));
    setup();
}
void init()
{
    add_action("do_knock", "knock");
    add_action("do_out", "tiao");
}
int do_knock(string arg)
{
    object me,killer;
    me = this_player();
    if ( !arg || ( arg != "bell" ) ) return notify_fail("��Ҫ��ʲ�᣿\n");
    if((int)me->query("qi")*100/(int)me->query("max_qi") < 40 && random((int)me->query_str()) < 15)
    {
        killer = new(CLASS_D("shaolin") + "/qing-xiao");
        me->set_temp("last_damage_from",killer);
        me->die();
        destruct(killer);
        return 1;
    }
    else
        me->add("qi", -20);
    if ( random((int)me->query_dex()) < 20 )
    {
        message_vision("$Nһ��С���õ��Լ�ͷ���ˡ�\n", me);
        //me->add("qi", -10 - me->query("qi"));
        me->unconcious();
    } else {
        mapping mine;
        mine = me->query_entire_dbase();
        message_vision("$N����һ�´��ӣ����ۡ���������������������\n", me);
        write("������Ѹ�װ��������ը�죬��ͷ����һƬ��Ϳ��\n"
            "ȫ��ҡҡ��׹������֧���Ų����ڵ��ϡ�����һ��\n"
            "���������㣬�øϿ��뿪�����Ȼ��û���ˡ�\n");
        mine["combat_exp"] += 1;
    }
    return 1;
}

    int do_out(string arg)
{
        object me;
    int i,j,my_dex, ging_cost, qi_cost, my_kar,tiaolou_cnt;
    me = this_player();
    my_dex = (int)me->query_dex();
    my_kar = (int)me->query_kar();
    i = (my_dex + my_kar)*5+ random(200);
    j = random(i);
    ging_cost = 600 / (int)me->query_int();
    qi_cost = 800 / (int)me->query_int();
    tiaolou_cnt=0;
    if (!arg||arg!="lou") {
    tell_room(environment(me), me->name() +"�벻������¥������˫��ȴ����ʹ����ɪɪ����!\n", ({me}));
    write("����˵������ϸߣ���֪������ʲôë��\n");
    return 1;
    }
     if((int)me->query("tiaolou_cnt")>=6000)
{     if(random((int)me->query("kar"))>20){
    	me->set_skill("dodge",(int)me->query_skill("dodge",1)+1);
    	 write(HIG"����Ṧ������!\n");
         CHANNEL_D->do_channel(this_object(), "rumor",
            sprintf("����%s��ֲ�и����¥,�Ṧ����ȡ���˳���Ľ�չ��\n", me->name(1)));}
         me->set("tiaolou_cnt",0);
         return 1;
     }
    if((int)me->query("jing") < ging_cost || (int)me->query("qi") < qi_cost)
     { 
    message_vision("$N����ʧ��,��,��һ��̾�˿���,�ʹ�¥��������ȥ��\n", me);
    message_vision("ֻ�����须��һ��$N����¥������������\n", me);
    me->move(__DIR__"gulou");
    me->unconcious();
    return 1;
    }
    if ((int)me->query_skill("dodge", 1)<100 && j < 30)
    {

                me->move(__DIR__"zhonglou");
            
                me->unconcious();


    }
    else if((int)me->query("neili")<2000 && j < 15) {
        message_vision("$N���ϴ�����һ���������˳�ȥ��\n", me);
        
       me->move(__DIR__"zhonglou");
       message_vision("ֻ�����须��һ��$Nˤ�˸�������\n", me);
        me->unconcious();
        }
    else {
    	message_vision("$N���ϴ�����һ���������˳�ȥ��\n", me);
        me->move(__DIR__"zhonglou1");

        message_vision("ֻ�����须��һ��$N��¥������������\n", me);
        tell_object(me,"��о����Լ����Ṧ���н����ˣ�\n");
                if (me->query_skill("dodge", 1)<200)
                me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
                else if (me->query_skill("dodge", 1)<700)
                me->improve_skill("dodge", (int)me->query_skill("dodge", 1)*my_kar/30);
                else if (random(my_kar)>15)
                 me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
                else me->improve_skill("dodge", (int)me->query_skill("dodge", 1)/2);

        me->add("tiaolou_cnt",1);
        me->receive_damage("jing", ging_cost );
        me->receive_damage("qi", qi_cost );

        me->set_temp("die_for","����¥��������ˤ");
        me->delete_temp("last_damage_from");
    
   }
    return 1;
}
string look_bell()
{
    return
    "����������������������������������������������\n"
    "����������������������������������������������\n"
    "������������������������Ի��������������������\n"
    "����������������������������������������������\n"
    "��������������һ����У�ײһ���ӡ�������������\n"
    "����������������������������������������������\n"
    "�����������������롡����죩������������\n"
    "����������������������������������������������\n"
    "����������������������������������������������\n";
}
string look_out()
{
    return  "��������¥����Ĵ�̨�����������ң����������ɽ����\n"
"�Լ��������Ƶ���ɽ�������̳��������۵ס���˵�ڴ˵�\n"
"������������ֱ�ӽ����������޴����洦��\n";
}

