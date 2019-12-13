// Room: /d/shaolin/gulou7.c
// Date: YZC 96/01/19
inherit ROOM;
string look_drum();
string look_out();
void create()
{
    set("short", "��¥�߲�");
    set("long", @LONG
������ǹ�¥֮����ֱ�������ı���һֻ��ġ���Ĺ���ͨ�죬
���ɰ���ľ���ɡ���ͷ����ˮţƤ����һ�Ѵ�ͭ�����ڹ����Ե��
������һȦ���գ���������Ϊ��λ����γɵġ�������ķ���һ
��һ�˸ߵļ����ϣ����ӵײ�����������鳡�����ɽ�紵����
����˭������ס���һ�¹�(drum)���ԡ����⿴���и��ܴ�ĺ�
����̨(window)���������վһ���ˣ�������벻���Ļ�����
¥(tiao lou)��һ���õĽ��������
LONG
    );
    set("exits", ([
        "down" : __DIR__"gulou6",
    ]));
    set("item_desc",([
        "drum"      :   (: look_drum :),
        "window"       :   (: look_out :),
    ]));
    set("objects",([
        CLASS_D("shaolin") + "/qing-wen" : 1,
    ]));
    setup();
}
void init()
{
    add_action("do_hit", "hit");
    add_action("do_out", "tiao");
}
int do_hit(string arg)
{
     object me, killer;
    me = this_player();
    if ( !arg || ( arg != "drum" ) ) return notify_fail("��Ҫ��ʲ�᣿\n");
    if((int)me->query("qi")*100/(int)me->query("max_qi") < 30)
    {
        killer = new(CLASS_D("shaolin") + "/qing-xiao");
	me->set_temp("last_damage_from",killer);
                me->die();
        destruct(killer);
        return 1;
    }
    else
        me->add("qi", -30);
    if ( random((int)me->query_str()) < 30 )
    {
        message_vision("$Nһ��С���õ��Լ�ͷ���ˡ�\n", me);
        //me->add("qi", -10 - me->query("qi"));
        me->unconcious();
    }
    else
    {
        mapping mine;
        mine = me->query_entire_dbase();
        message_vision("$N����һ�´�ģ����ˡ���������������������\n", me);
        write("������Ѹ�װ��������ը�죬��ͷ����һƬ��Ϳ��\n"
            "ȫ��ҡҡ��׹������֧���Ų����ڵ��ϡ�����һ��\n"
            "���������㣬�øϿ��뿪�����Ȼ��û���ˡ�\n");
        if ( mine["potential"] - mine["learned_points"] < 100 )
            mine["potential"] += 1;
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
    { if(random((int)me->query("kar"))>20) {
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
    message_vision("ֻ�����须��һ��$N�ӹ�¥������������\n", me);
    me->move(__DIR__"gulou");
    me->unconcious();
    return 1;
    }
    if ((int)me->query_skill("dodge", 1)<100 && j < 10)
    {

                me->move(__DIR__"gulou");
                me->command("chat* "+"help!");
                me->die();

        //destruct(killer);
    }
    else if((int)me->query("neili")<2000 && j < 15) {
        message_vision("$N���ϴ�����һ���������˳�ȥ��\n", me);
        
        me->move(__DIR__"gulou");
       message_vision("ֻ�����须��һ��$Nˤ�˸�������\n", me);
        me->unconcious();
        }
    else {
    	message_vision("$N���ϴ�����һ���������˳�ȥ��\n", me);
reset_eval_cost();
     me->move(__DIR__"gulou");
    message_vision("ֻ�����须��һ��$N��¥������������\n", me);
     tell_object(me,"��о����Լ����Ṧ���н����ˣ�\n");
                if (me->query_skill("dodge", 1)<400)
                me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
                else if (me->query_skill("dodge", 1)<700)
                me->improve_skill("dodge", (int)me->query_skill("dodge", 1)*my_kar/30);
                else if (random(my_kar)>15)
                 me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
                else me->improve_skill("dodge", (int)me->query_skill("dodge", 1)/2);

         
        me->add("tiaolou_cnt",1);
        me->receive_damage("jing", ging_cost );
        me->receive_damage("qi", qi_cost );
        me->set_temp("die_for","�ӹ�¥��������ˤ");
        me->delete_temp("last_damage_from");
    
   }
    return 1;
}
string look_drum()
{
    return
    "��������������������������������������������\n"
    "��������������������������������������������\n"
    "������������������������Ի������������������\n"
    "��������������������������������������������\n"
    "��������������һ����������һ�ιġ�����������\n"
    "��������������������������������������������\n"
    "��������������������������������������\n"
    "��������������������������������������������\n"
    "��������������������������������������������\n";
}
string look_out()
{
    return  "�����ǹ�¥����Ĵ�̨�����������ң����������ɽ����\n"
"�Լ��������Ƶ���ɽ�������̳��������۵ס���˵�ڴ˵�\n"
"������������ֱ�ӽ����������޴����洦��\n";
}
