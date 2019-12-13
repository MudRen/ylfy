
#include <ansi.h>

inherit ITEM;
void de_group(object *fighters);
void checking(object ob1, object ob2);
int att_fight(object ob1,object ob2);
void recover(object ob);
int sort_user(object ob1,object ob2);
string clear_title(string arg);
void add_title(object me,string arg);

#define lunjian1 "/d/huashan/lunjian1"

void create()
{
    set_name(HIR"����Ӣ�۹�"NOR, ({ "drum" }) );
    set_weight(5000000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
      set("unit", "ֻ");
	set("icon", "05002");
      set("long", "����һֻţƤ�Ƴɵľ޹ģ�������ʿ�ڻ�ɽ�۽�ʱ����(knock)����ʼ���䡣\n");
    }
}
int init()
{
    add_action("do_knock", "knock");
}
int do_knock(string arg)
{
    object ob, me, *env, *fighters;
    int i, j;
    me = this_player();
    ob = environment(me);
    if (!wizardp(me))
        return notify_fail("�˳���ֻ������ʦ����!!!!!!��\n"); 
    if(!arg || arg!="drum" )    return notify_fail("��Ҫ��ʲô��\n");
    if(query("is_drum_knocked") )
        return notify_fail("�������Ѿ���ʼ�ˣ������ٻ����ˡ�\n");
    env = all_inventory(ob);
    for(i=0, j=0;i<sizeof(env);i++) {
        if(wizardp(env[i]) && !wizardp(me) )
        return notify_fail("�����ٿ������ᣬ��������ʦ���ġ�\n");
        if(!userp(env[i]) || wizardp(env[i]) )  
            continue;
//      if (env[i]->query("mud_age")<86400*4)  continue;
        if (wizardp(me))
            env[i]->set("title",clear_title(env[i]->query("title")));
        if(j==0)    fighters = ({ env[i] });
        else        fighters += ({ env[i] });
        j++;
    }
    if(j < 4 )
        return notify_fail("��������̫���ˣ��㻹���ȶ��ټ�������Ұɡ�\n");

    message_vision(BOLD "\n\n\t$N�����˱��䳡�ϵĴ�ģ��������ˣ�������Ѫ���ڡ�\n\n"+NOR, me);
        if( wiz_level(me) >= wiz_level("(arch)") )
        set("drum_knocked", me->query("id") );
    else
        delete("drum_knocked");
    set("is_drum_knocked",1 );
    delete("round");
    delete("loop");
    environment(this_object())->delete("exits");
    de_group(fighters);
    return 1;
}
int sort_user(object ob1,object ob2)
{
      if (ob1->query("combat_exp") < ob2->query("combat_exp"))
            return 1;
      else return -1;
}

int sort_winner(object ob1,object ob2)
{
      mapping arena=query("arena");
      if (!ob1 && !ob2) return 0;
      if (!ob1) return 1;
      if (!ob2) return -1;
      if ((arena[ob1] == arena[ob2]) && (ob1->query("combat_exp") > ob2->query("combat_exp")))
            return -1;
      if (arena[ob1] > arena[ob2])
            return -1;
      else return 1;
}

void de_group(object *fighters)
{
    int i,j,k;
    string msg,file;
    object *list,no1,no2,no3,no4;
    mapping arena;
    object room=environment();
    
    if(sizeof(fighters)<=1)       return;
    for (i=0;i<60;i++)
    if (query("group"+i)) delete("group"+i);
    while (query("group"+i)) delete("group"+i);
    if(sizeof(fighters)<8){
        if (query("loop")){
            file = "seperator\n";
            arena = query("arena");
            list = sort_array( keys(arena ),"sort_winner",this_object());
            for (i=0;i<sizeof(list);i++)
                if (!undefinedp(list[i])){
                   no1=list[i];
                   break;
                }
            i++;
            for (i=0;i<sizeof(list);i++)
                if (!undefinedp(list[i])){
                   no2=list[i];
                   break;
                }
            i++;
            for (i=0;i<sizeof(list);i++)
                if (!undefinedp(list[i])){
                   no3=list[i];
                   break;
                }
            i++;
            for (i=0;i<sizeof(list);i++)
                if (!undefinedp(list[i])){
                   no4=list[i];
                   break;
                }
            if (no1){
            tell_room(room, HIW+"\n\n���α�����Ľ��:\n"+HIM+"          ��һ����"
                +no1->query("name")+"("+no1->query("id")+")��\n"+NOR);
            file += no1->query("name")+" ("+no1->query("id")+")\n";
            }
            if (no2){
            tell_room(room, HIR+"          �ڶ�����"
                +no2->query("name")+"("+no2->query("id")+")��\n"+NOR);
            file += no2->query("name")+" ("+no2->query("id")+")\n";
            }
            if (no3){
            tell_room(room, HIY+"          ��������"
                +no3->query("name")+"("+no3->query("id")+")��\n"+NOR);
            file += no3->query("name")+" ("+no3->query("id")+")\n";
            }
            if (stringp(query("drum_knocked"))){
                log_file("/fight/lunjian1", file);
                if (no1){
                    add_title(no1,"�����������һ");
                    no1->add("potential",5000); 
                        new("/clone/money/thousand-gold",100)->move(no1);
                    if (no1->query("PKS")>10){    
                        no1->add("PKS",-10);
                    }else no1->delete("PKS"); 
                }
                if (no2){
                    add_title(no2,"����������ڶ�");
                    no2->add("potential",3000); 
                        new("/clone/money/thousand-gold",50)->move(no2);
                    if (no2->query("PKS")>7){   
                        no2->add("PKS",-7);
                    }else no2->delete("PKS");
                }
                if (no3){
                    add_title(no3,"�������������");
                    no3->add("potential",1000);     
                        new("/clone/money/thousand-gold",30)->move(no3);
                    if (no3->query("PKS")>5){    
                        no3->add("PKS",-5);
                    }else no3->delete("PKS");
                }
            }

            delete("drum_knocked");
            delete("lunshu");
         environment()->set("exits",([ "south":"/d/huashan/houzhiwangyu",]));
         delete("is_drum_knocked");
            return;
        }
        set("loop",1);
        msg = BOLD+"\n\n�������"+chinese_number((int)query("lunshu")+1)+"��(ѭ����)���̣�\n\n"+NOR;
        k=0;
        for (i=0;i<sizeof(fighters);i++){
            for (j=i;j<(sizeof(fighters)-1);j++,k++){
                set("group"+k,([ fighters[i]:fighters[j+1] ]));
                msg += ((string)fighters[i]->query("name")+HIY+"--V.S.--"+NOR+(string)fighters[j+1]->query("name")+(k%3==2?"\n\n":"\t"));
            }
            if (objectp(fighters[i])){
                if (sizeof(arena))
                    arena += ([ fighters[i] : 0 ]);
                else
                    arena = ([ fighters[i] : 0 ]);
            }
       }
    }else{
        msg = BOLD+"\n\n�������"+chinese_number((int)query("lunshu")+1)+"��(��̭��)���̣�\n\n"+NOR;
        set("loop",0);
        list = sort_array(fighters, "sort_user",this_object());
        for (i=0;i<sizeof(list);i++){
                if (sizeof(arena))
                    arena += ([ list[i] : 0 ]);
                else
                    arena = ([ list[i] : 0 ]);
                
        }
        i=0;
        if (sizeof(list)%2){
            i=1;
            msg += HIY+((string)list[0]->query("name")+"------(������ս)\t"+NOR);
            set("group0",([ list[0]: 0 ]) );

        }
        for (i=0;i<(sizeof(list))/2;i++){
                set("group"+i,([
                list[i] : list[sizeof(list)/2+i]
                ]) );
                msg += ((string)list[i]->query("name")+HIC+"--V.S.--"+NOR+(string)list[sizeof(list)/2+i]->query("name")+(i%3==2?"\n\n":"\t"));
        }
    }
    msg += "\n";
    room->set("item_desc/paizi",msg);
    tell_room(room, msg);
    set("round",0);
    set("arena",arena);
    remove_call_out("start_fight");
    call_out("start_fight", 5);
}

int filter_user(object ob1,object ob2)
{
    mapping arena=query("arena");
    return (int)arena[ob1];
}

void start_fight()
{
    int round=query("round");
    mapping fighters,arena=query("arena");
    object room=environment();
    object ob1,ob2,*list;
    if (mapp(fighters=query("group"+round))){
        if (sizeof(keys(fighters)))
        ob1=keys(fighters)[0];
        if (ob1)
            ob2=fighters[ob1];
        else if (sizeof(values(fighters)))
            ob2=values(fighters)[0];
        round ++;
        set("round",round);
        if (ob1 && !ob2){
            arena[ob1] += 1;
            tell_room(room, BOLD+"\n��"+chinese_number((int)query("lunshu")+1)+"�ֵ�"+chinese_number(round)+"�غϣ�  "
            +ob1->query("name")+"("+ob1->query("id")+")"+HIY+"---------��ս!\n"+NOR);
            remove_call_out("start_fight");
            call_out("start_fight", 1);
            return;
        }
        if (ob2 && !ob1){
            arena[ob2] += 1;
            tell_room(room, BOLD+"\n��"+chinese_number((int)query("lunshu")+1)+"�ֵ�"+chinese_number(round)+"�غϣ�  "
            +ob2->query("name")+"("+ob2->query("id")+")"+HIY+"---------��ս!\n"+NOR);
            remove_call_out("start_fight");
            call_out("start_fight", 1);
            return;
        }
        if (!ob1 && !ob2){
            tell_room(room, BOLD+"\n��"+chinese_number((int)query("lunshu")+1)+"�ֵ�"+chinese_number(round)+"�غϣ�  "
            +HIY+"-----------SKIP----------\n"+NOR);
            remove_call_out("start_fight");
            call_out("start_fight", 1);
            return;
        }
        tell_room(room, BOLD+"\n��"+chinese_number((int)query("lunshu")+1)+"�ֵ�"+chinese_number(round)+"�غϣ�  "
        +ob1->query("name")+"("+ob1->query("id")+")"+HIY+"---V.S.---"+NOR+BOLD
        +ob2->query("name")+"("+ob2->query("id")+")\n"+NOR );
        if (!room=find_object(lunjian1))
             room=load_object(lunjian1);
        recover(ob1);
        recover(ob2);
        message_vision(HIW+"\n$N��$nʩչ�Ṧ,˫˫Ծ����̨��\n\n"+NOR,ob1,ob2);
        ob1->move(room);
        ob2->move(room);
        message("vision",HIW+"\n"+ob1->name()+"��"+ob2->name()+"һǰһ��Ծ��������\n\n"+NOR,room,({ob1,ob2}));
        set("time",3);
        remove_call_out("att_fight");
        call_out("att_fight",1,ob1,ob2);
    }else{
        tell_room(room, HIW+"�������"+chinese_number((int)query("lunshu")+1)+"�ֱ���������\n"+NOR);
        environment()->set("item_desc/paizi","���ڻ�û��ʼ�����أ�");
        add("lunshu", 1);
        list = filter_array(keys(query("arena")), "filter_user", this_object());
        de_group(list);
    }    
}


void checking(object ob1, object ob2)
{
    object winner,room;
    mapping arena;
    if (!room=find_object(lunjian1))
         room=load_object(lunjian1);
    if (ob1 && ob2)
        if (present(ob1,room) && present(ob2,room) ){
            remove_call_out("checking");
            call_out("checking",2, ob1, ob2);
            return ;
        }
    if (!ob1 && !ob2)
        tell_room(environment(), BOLD "����˫����Ȩ,������һ�ֱ�����\n"NOR);
    else    if (ob1 && (!ob2 || !present(ob2,room)) ){
            winner = ob1;
            message("vision",HIC+ob1->name()+"������Ц������������ȥ��\n"+NOR,room,({ob1}));
        }else if (!ob1 || !present(ob1,room) ){
            winner = ob2;
            message("vision",HIC+ob2->name()+"������Ц������������ȥ��\n"+NOR,room,({ob2}));
        }else
            tell_room(environment(), BOLD "����˫����Ȩ,������һ�ֱ�����\n"NOR);
    if(winner) {
        arena=query("arena");
        arena[winner] += 1;
        if (ob1) ob1->move(environment());
        if (ob2) ob2->move(environment());
        message_vision(HIC+"$N������Ц������̨������������\n"+NOR,winner);
        tell_room(environment(), BOLD "��һ�غϵĽ���ǣ�  "+winner->query("name")+" ʤ��\n"NOR);
        recover(ob1);    recover(ob2);
    }
    remove_call_out("start_fight");
    call_out("start_fight", 5);
}
int att_fight(object ob1,object ob2)
{
    object room;
    if (!ob1 || !ob2){
        remove_call_out("start_fight");
        call_out("start_fight", 5);
        return 1;
    }
    if (!room=find_object(lunjian1))
         room=load_object(lunjian1);
    if (present(ob1,room) && present(ob2,room) ){
        if (!ob1->is_killing(ob2) || !ob2->is_killing(ob1)){
            if (query("time")){
            tell_object(ob1,"\t\t"+HIR+"==="+CHINESE_D->chinese_number(query("time"))+"===\n\n"+NOR);
            tell_object(ob2,"\t\t"+HIR+"==="+CHINESE_D->chinese_number(query("time"))+"===\n\n"+NOR);
            add("time",-1);
            call_out("att_fight",5,ob1,ob2);
            return 1;
            }
            tell_room(room,HIY "\t-------  ��     ʼ  -------\n\n" NOR);
            message_vision("\n$N����$n�ȵ�����" + RANK_D->query_rude(ob2) + "�����ղ������������һ��\n\n", ob1, ob2);
        }
        if (!ob1->is_killing(ob2)) ob1->kill_ob(ob2);
        if (!ob2->is_killing(ob1)) ob2->kill_ob(ob1);
    }
    remove_call_out("checking");
    call_out("checking", 2, ob1, ob2);
    return 1;
}
void recover(object me)
{
    if (!me)    return;
       if (!living(me)) me->revive();
        me->set("eff_jing",me->query("max_jing"));
    me->set("jing",me->query("max_jing"));
    me->set("eff_qi",me->query("max_qi"));
    me->set("qi",me->query("max_qi"));
    if (me->query("neili")<me->query("max_neili"))
        me->set("neili",me->query("max_neili"));
        if (me->query("jingli")<me->query("max_jingli"))
                me->set("jingli",me->query("max_jingli"));
        me->set("food",me->max_food_capacity());
        me->set("water",me->max_water_capacity());
        me->clear_condition();
}

string clear_title(string arg)
{
     if (!arg) return "";
    if( (strsrch(arg, "�����������һ") >= 0)
      ||(strsrch(arg, "����������ڶ�") >= 0)
      ||(strsrch(arg, "�������������") >= 0))
        {
        arg = replace_string(arg, HIY+"�����������һ"+NOR,"");
        arg = replace_string(arg, HIY+"����������ڶ�"+NOR,"");
        arg = replace_string(arg, HIY+"�������������"+NOR,"");
        }
    return arg;
}

void add_title(object me,string arg)
{
    string title;
    title=HIW+arg+NOR+clear_title(me->query("title"));
    me->set("title",title);
}

int give_money(object *players,object *fighters)
{
    if (query("drum_knocked")){
             message("vision",query("drum_knocked")+"Ц�����ضԴ��˵������������������л������\n",environment());
        foreach (object user in players){
                if (user && !wizardp(user) && ( environment()==environment(user) )){
                        new("/clone/money/thousand-gold")->move(user);
                        new("/clone/money/thousand-gold")->move(user);
                }
        }
             message("vision",query("drum_knocked")+"�������Ľ�����ʿÿ�˶��Ž�Ʊ����СС��˼��Ц�ɣ�Ц�ɡ���\n",environment());
    }
    de_group(fighters);
    return 1;
}
int query_autoload() { return 1; }
