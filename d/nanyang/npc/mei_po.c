// mei_po.c
#include <ansi.h>
inherit NPC;
string marry();
string unmarry();
string ask_huajiao();
void create()
{
        set_name("ý��", ({ "mei_po" }) );
        set("title", "����");
        set("gender", "Ů��" );
        set("age", 43);
        set("long",
                "һλ�����ܸɵ���ý�š�\n");
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set("inquiry", ([
         "�����ǵ������˺���?": (: command("chat* ok") :),
          "���" : "�ǰ�... ����Ϳ��Ե޽�(marry)�ͽ��(unmarry)��Լ�ġ�",
         "����" : (: ask_huajiao :), 
         "�⻨��" : (: ask_huajiao :), 
        ]) );
        set_skill("literate", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        setup();
        add_money("gold", 1);
      carry_object("/clone/cloth/pink_cloth")->wear();
}
void init()
{
        ::init();
        add_action("do_marry", "marry");
        add_action("do_unmarry", "unmarry");
        add_action("do_name","��");
}
int do_marry(string arg)
{
    object obj,ob, me, old_target;
    string target;
    me = this_player();
    if ( (string)me->query("gender") == "����")
        return notify_fail(CYN"ý��˵�������޸����ԣ�����������\n"NOR);
    if (((int)me->query("age") < 18) && (me->query("gender") == "����")
        ||((int)me->query("age") < 16) && (me->query("gender") == "Ů��"))
        return notify_fail(CYN"ý��˵���������ڻ����ᣬ�Ժ���˵�ɣ�\n"NOR);
    if (me->is_busy())
        return notify_fail(CYN"ý��˵������������æ���ء�\n"NOR);
    if( me->is_fighting(this_object()) )
    {
        if( !this_object()->is_killing(me) )
            this_object()->kill_ob(me); 
        return notify_fail(CYN"ý��˵������������ȥ����ɻ飡\n"NOR); 
    }
    if( this_object()->is_fighting() )
        return notify_fail(CYN"ý��˵����û����������˵�����\n"NOR);
    if( !living(this_object()) )
        return notify_fail("�㻹������취��ý�ž��Ѱɡ�\n"); 
    if( me->is_fighting() )
        return notify_fail(CYN"ý��˵�����ٺ٣����Ȼ������������������˵�ɣ�\n"NOR);
    if( !environment() || base_name(environment()) != query("startroom"))
        return notify_fail(CYN"ý��˵�������Ǳ�Ǹ��������һ�µ�����ׯ�����Ұɡ�\n"NOR);
    if( (string)me->query("class")=="bonze" ) 
        return notify_fail(CYN"ý��Ц������������ô������Ҳ�뿪ɫ������?\n"NOR);
    if(!arg || !objectp(obj = present(arg, environment(me)))
        || !find_player(arg) )
        return notify_fail(CYN"ý��˵���������˭ϲ����Ե��\n"NOR);
    if( me->query_temp("pending/pro") )
        return notify_fail(CYN"ý��˵������Ļ������ڽ����С�\n"NOR);
    if( obj->query_temp("pending/pro") )
        return notify_fail(CYN"ý��˵������������˽�����\n"NOR);
    if( !obj->is_character() )
        return notify_fail(CYN"ý��˵�������ⲻ�����Լ�������\n"NOR);
    if( (string)obj->query("class")=="bonze" ) 
        return notify_fail(CYN"ý��Ц�����������˼ҿ��ǳ����ˣ�����˼ҿ���Ц�ˡ�\n"NOR);
    if(obj == me)
        return notify_fail(CYN"ý��˵�������ⲻ�����Լ�������\n"NOR);
        if (stringp(target=me->query("marry"))){
            if (objectp(ob=present("marry ring",me))){
            if ( obj == present(target, environment(me)) ){
                    if (objectp(ob=present("marry ring",obj))){
                    command("say ���Ǳ������Ƿ���ѽ��\n");
                    return 1;
                }else{
                    command("say ���Ǳ������Ƿ���ѽ��\n");
                        ob = new("/clone/misc/marry_ring");
                        ob->move(obj);
                    ob->autoload();
                    message_vision("$N����$pһ������ָ��\n\n" ,this_object(), obj);
                    command("say С�ı���ѽ���´οɱ��ˣ�\n");
                    return 1;
                }
            }else
                if ((string)me->query("gender") == "Ů��") 
                    return notify_fail(CYN"ý��˵�������Ѿ����з�֮���ˣ����ﲻ�����ػ�ġ�\n"NOR);
                else
                    return notify_fail(CYN"ý��˵�������Ѿ����и�֮���ˣ����ﲻ�����ػ�ġ�\n"NOR);
        }else{
                ob = new("/clone/misc/marry_ring");
                ob->move(me);
            ob->autoload();
            message_vision("$N����$pһ������ָ��\n\n" ,this_object(), me);
            command("say С�ı���ѽ���´οɱ��ˣ�\n");
            call_out("do_marry",1,arg);
            return 1;
        }
    }
        if (stringp(target=obj->query("marry"))){
            if (objectp(ob=present("marry ring",obj))){
            if ( me->query("id") == target ){
                    if (objectp(ob=present("marry ring",me))){
                    command("say ���Ǳ������Ƿ���ѽ��\n");
                    return 1;
                }else{
                    command("say ���Ǳ������Ƿ���ѽ��\n");
                        ob = new("/clone/misc/marry_ring");
                        ob->move(me);
                    ob->autoload();
                    message_vision("$N����$pһ������ָ��\n\n" ,this_object(), me);
                    command("say С�ı���ѽ���´οɱ��ˣ�\n");
                    return 1;
                }
            }else   if((string)obj->query("gender") == "Ů��") 
                    return notify_fail(CYN"ý��˵������ϧ���Ѿ����з�֮���ˣ����ﲻ�����ػ�ġ�\n"NOR);
                else
                    return notify_fail(CYN "ý��˵������ϧ���Ѿ����и�֮���ˣ����ﲻ�����ػ�ġ�\n"NOR);
        }else{
                ob = new("/clone/misc/marry_ring");
                ob->move(obj);
            ob->autoload();
            message_vision("$N����$nһ������ָ��\n\n" ,this_object(), obj);
            command("say С�ı���ѽ���´οɱ��ˣ�\n");
            call_out("do_marry",1,arg);
            return 1;
        }
    }
    if( !living(obj) )
        return notify_fail(CYN"ý��˵����" + obj->name() + "�޷����㹲������\n"NOR); 

    if((string)obj->query("gender") == (string)me->query("gender"))
        return notify_fail(CYN"ý��˵�����㲻��" + RED"AIDS"CYN + "��\n"NOR);
    if( !userp(obj) )
        return notify_fail(CYN"ý��˵�����Բ�����ֻ��Ȣ��ҡ�\n"NOR);
    if( (object)obj->query_temp("pending/marry")!=me )
    {
        if ((string)obj->query("gender") == "Ů��") 
            message_vision(MAG "\n$N����$n˵������Ը��޸�����\n\n"NOR, me,obj);
        else
            message_vision(MAG "\n$N����$n˵������Ը��Ȣ����\n\n"NOR, me,obj);
        if( objectp(old_target = me->query_temp("pending/marry")) && old_target != obj )
            tell_object(old_target, YEL + me->name() + "ȡ���˺��������ͷ��\n" NOR);
           
        me->set_temp("pending/marry", obj);
        if ((string)obj->query("gender") == "Ů��") 
            tell_object(obj, MAG "�����Ը��޸���������Ҳ��" + me->name()
            + "("+(string)me->query("id") + ")"+ "��һ�� marry ָ�\n" NOR);
        else
            tell_object(obj, MAG "�����Ը��Ȣ��������Ҳ��" + me->name() + 
            "("+(string)me->query("id") + ")"+ "��һ�� marry ָ�\n" NOR);
                write(MAG  "�����㼱�����������������˵ͬ��...\n" NOR);
                return 1;
    }
    message_vision(MAG "\n$N����$n˵������Ը�⣡\n\n"NOR, me,obj);           
    CHANNEL_D->do_channel(this_object(), "chat",obj->name(1)+"��"+me->name(1)+"���ڿ�ʼ������! \n");
    message_vision(MAG "ý��˵�������������ǵ������ˡ�\n\n" NOR,obj, me);
    message_vision(MAG "ý�ź������� ��� ඣ�\n" NOR,obj, me);
    me->set_temp("pending/pro", 1);
    obj->set_temp("pending/pro", 1);
    me->set_temp("couple/couple_name",(string)obj->name(1));
    me->set_temp("couple/couple_id",obj->query("id"));
    obj->set_temp("couple/couple_name",(string)me->name(1));
    obj->set_temp("couple/couple_id",me->query("id"));
    return 1;
}
int do_unmarry()
{
    object me, obj,ob;
    string target;
    me = this_player();       
    if (me->is_busy())
        return notify_fail("ý��˵������������æ���ء�\n");
    if( me->is_fighting(this_object()) )
    {
        if( !this_object()->is_killing(me) )
            this_object()->kill_ob(me); 
        return notify_fail("ý��˵��������������ȥ���䣡\n");
    }
    if( this_object()->is_fighting() )
        return notify_fail("ý��˵����û����������˵�����\n");
    if( !living(this_object()) )
        return notify_fail("�㻹������취��ý�ž��Ѱɡ�\n"); 
    if( me->is_fighting() )
        return notify_fail("ý��˵�����ٺ٣����Ȼ������������������˵�ɣ�\n");
    if( !environment()||base_name(environment()) != query("startroom") )
        return notify_fail("ý��˵�������Ǳ�Ǹ��������һ�µ�����ׯ�����Ұɡ�\n");
        if (!stringp(target=me->query("marry"))){
        if ((string)me->query("gender") == "Ů��") 
            return notify_fail("ý��˵�����㻹δ���Ϲ�����\n");
        else
            return notify_fail("ý��˵�����㻹δ�����Ű���\n");
    }
    if( !objectp(obj = present(target, environment(me))))
        return notify_fail(CYN "ý��˵������İ������ڲ��ڳ���\n" NOR);
    if( (object)obj->query_temp("pending/unmarry")!=me )
    {
        message_vision(MAG "\n$N����$n˵�����Բ��𣬲����Ҳ����㣬ֻ��... ���Ǻþۺ�ɢ������?\n\n"NOR, me,obj);           
        me->set_temp("pending/unmarry", obj);
        if ((string)obj->query("gender") == "Ů��") 
            tell_object(obj, MAG "����㲻�����ˣ�����Ҳ��" 
                        +me->name() + "("+(string)me->query("id")+
                        ")"+ "��һ�� unmarry ָ�\n" NOR);
        else
            tell_object(obj, MAG "����㲻�����ˣ�����Ҳ��" +me->name() + "("+(string)me->query("id")+")"+ "��һ�� unmarry ָ�\n" NOR);
        write(MAG "���������ȴ�����İ��µĻش�...\n" NOR);
        return 1;
    }
       
    message_vision(MAG "\n$N����$n˵������Ȼ��Ե�����Ǿ͸��߸���·�ɡ�\n\n"NOR, me,obj);           
    message_vision(MAG "ý��˵����$N��$n�����ڿ�ʼ���Ƿ���! \n" NOR, obj, me);
    CHANNEL_D->do_channel(this_object(), "chat",
    sprintf( "��ϧ%s��%s��һ���������ַ�... ��Ը�����档\n", me->name(), obj->name()));
    me->delete("couple");
    obj->delete("couple");
    me->add("unmarried", 1);
    obj->add("unmarried", 1);
    me->delete("marry");
    obj->delete("marry");
        if (objectp(ob=present("marry ring",me)))
        destruct(ob);
        if (objectp(ob=present("marry ring",obj)))
        destruct(ob);
    return 1;
}
int do_name(string arg)
{
    object me, obj,marry_card1,marry_card2;
    me = this_player();       
    if (me->is_busy())
        return notify_fail("ý��˵������������æ���ء�\n");
    if( me->is_fighting(this_object()) )
    {
        if( !this_object()->is_killing(me) )
            this_object()->kill_ob(me); 
        return notify_fail("ý��˵������������ȥ����ɻ飡\n");
    }
    if( this_object()->is_fighting() )
        return notify_fail("ý��˵����û����������˽�����\n");
    if( !living(this_object()) )
        return notify_fail("�㻹������취��ý�ž��Ѱɡ�\n"); 
    if( me->is_fighting() )
        return notify_fail("ý��˵�����ٺ٣����Ȼ������������������˵�ɣ�\n");
    if( !environment()||base_name(environment()) != query("startroom") )
        return notify_fail("ý��˵�������Ǳ�Ǹ��������һ�µ�����ׯ�����Ұɡ�\n");
    if( !me->query_temp("pending/pro") )
        return notify_fail("ý��Ц�����������㷸ʲôɵѽ��\n");
    if( !objectp(obj = present((string)me->query_temp("couple/couple_id"), environment(me)))
        || !find_player(me->query_temp("couple/couple_id")) )
        return notify_fail("ý��˵������İ��������뿪�ˣ�����ֻ���жϡ�\n");
    if(!arg)
        return notify_fail("ý��Ц�������Ұ�ʲôѽ��\n");
    if ( (me->query_temp("pending/pro")==1 && arg!="���")
        || (me->query_temp("pending/pro")==2 && arg!="����")
        || (me->query_temp("pending/pro")==3 && arg!=(string)me->query_temp("couple/couple_name")))
        return notify_fail("ý��Ц�������Ұ�ʲôѽ��\n");
    {
        if( (string)obj->query_temp("pending/act")!=arg ){
            if((me->query_temp("pending/pro")==3 && arg==(string)me->query_temp("couple/couple_name"))){
                tell_object(obj, MAG"��İ��������ź�����޶԰���...\n" NOR);
                arg=obj->query_temp("couple/couple_name");
            }else
                tell_object(obj, MAG"��İ��������ź����" + arg + "��...\n" NOR);
            write(MAG "���������ȴ�����İ���...\n" NOR);
            me->set_temp("pending/act", arg);
            return 1;
        }else{  switch(me->query_temp("pending/pro")){
            case 1:
                CHANNEL_D->do_channel(this_object(), "chat","һ�����! \n");
                me->add_temp("pending/pro",1);
                obj->add_temp("pending/pro",1);
                return 1;
            case 2:
                CHANNEL_D->do_channel(this_object(), "chat","���ݸ���! \n");
                me->add_temp("pending/pro",1);
                obj->add_temp("pending/pro",1);
                return 1;
            case 3:
                CHANNEL_D->do_channel(this_object(), "chat","���޶԰�! \n");
            }
        }
    }
    message_vision(MAG "ý��˵����$N��$n�������Ƿ�����! \n" NOR, obj, me);
    CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "��ϲ%s��%s��һ�����ϲ����Ե��\n", me->name(1), obj->name(1)));
    if ((string)me->query("gender") == "Ů��") {
        me->set("couple/couple_gender","�Ϲ�");
        obj->set("couple/couple_gender","����");
    }else{
        me->set("couple/couple_gender","����");
        obj->set("couple/couple_gender","�Ϲ�");
    }
    me->set("couple/couple_name",obj->name(1));
    obj->set("couple/couple_name",me->name(1));
    me->set("marry",obj->query("id"));        
    obj->set("marry",me->query("id"));        
    obj->set("couple/marry_time",time());
    me->set("couple/marry_time",time());
    me->save();
        obj->save();
    marry_card1 = new("/clone/misc/marry_ring");
    marry_card1->move(me);
    marry_card2 = new("/clone/misc/marry_ring");
    marry_card2->move(obj);
    me->delete_temp("pending");
    obj->delete_temp("pending");
    return 1;
}
string ask_huajiao()
{
    object me;
    me = this_player();
    
    if ( (string)me->query("gender") == "����")
        return ("���޸����ԣ�����������");
    if (((int)me->query("age") < 18) && (me->query("gender") == "����")
        ||((int)me->query("age") < 16) && (me->query("gender") == "Ů��"))
        return ("�����ڻ����ᣬ�Ժ���˵�ɣ�");
    if (me->is_busy())
        return ("��������æ���ء�");
    if( me->is_fighting(this_object()) )
    {
        if( !this_object()->is_killing(me) )
            this_object()->kill_ob(me); 
        return ("��������ȥ����! "); 
    }
    if( this_object()->is_fighting() )
        return ("û����������˵�����");
    if( me->is_fighting() )
        return ("�ٺ٣����Ȼ������������������˵�ɣ�");
    if( !environment() || base_name(environment()) != query("startroom"))
        return ("���Ǳ�Ǹ��������һ�µ�����ׯ�����Ұɡ�");
    if( me->query_temp("pending/pro") )
        return ("��Ļ������ڽ����С�");
    if( (string)me->query("class")=="bonze" ) 
        return ("��������������ʲô���Σ�����Ц�ˡ�");

          message_vision("ý���������´�����$Nһ�£�\n",me);
          me->set_temp("tmark/��", 1);
      return ("���⻨�Σ����ԡ�����˵��������ģ�һǧ��������һ�Ρ�");
}
int accept_object(object who, object ob)
{                    
        if ( who->query_temp("tmark/��") ) {
           if (ob->query("money_id") && ob->value() >= 10000000) {
                tell_object(who, "ý��һ������˵������л���ˣ������\n");               
                who->delete_temp("tmark/��");
                who->set_temp("asked",1);
                who->move("/d/nanyang/houyian.c");
                return 1;
                } else { 
                  message_vision("ý�Ų��ͷ��ض�$N˵������˵��Ҫһǧ�����ӵģ�û�������\n", who);
                return 0;
                }
        }

}

