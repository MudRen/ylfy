// marry_ring.c - ����ָ

#include <ansi.h>
#include <mudlib.h>
#include <armor.h>

inherit FINGER;

int do_coupletalk(string arg, int emote);

varargs mixed do_emote(object me, string verb, string arg,object couple_ob);

object find_player(string target)
{
      int i;
        object *objs;
        objs=users();
        for (i=0;i<sizeof(objs);i++)
                if (objs[i]->query("id")==target && interactive(objs[i]) && environment(objs[i]))
                        return objs[i];
        return 0;
}



void init()
{
        add_action("do_coupletalk_0", "ct");
        add_action("do_coupletalk_1", "ct*");
        add_action("do_coupletalk_2", "ct#");
}

int do_coupletalk_0(string arg) { return do_coupletalk( arg, 0 ); }

int do_coupletalk_1(string arg) { return do_coupletalk( arg, 1 ); }

int do_coupletalk_2(string arg) { return do_coupletalk( arg, 2 ); }

void dest() { destruct(this_object()); }

void owner_is_killed() { call_out("dest",2); }

int do_coupletalk(string arg, int emote)
{
        object me, couple_ob;

        me = this_player();

        if ( !me->query("couple/have_couple") )
                return notify_fail("��û�а��¡�\n");

        couple_ob = find_player( me->query("couple/couple_id") );
        if( !couple_ob )
                return  notify_fail("��İ��������޷������㣬�����Ѿ��뿪��Ϸ�ˡ�\n");

        if ((string)couple_ob->query("gender") == "����") 
                return  notify_fail("��ԭ���İ����Ѿ�����̫�࣬�㻹�ǰ������˰ɡ�\n");

        if ((string)couple_ob->query("class") == "bonze") 
                return  notify_fail("��ԭ���İ����Ѿ����˺��У��㻹�ǰ������˰ɡ�\n");

        if ( !arg || arg=="" || arg==" " ) {
                write( MAG "���������������İ����ˡ�\n" NOR);
                tell_room(environment(me), MAG + (string)me->name() + "��������������Լ���"+me->query("couple/couple_gender")
                        + (string)couple_ob->name(1) + "��\n" + NOR, ({me, couple_ob}));
                tell_object(couple_ob, sprintf(HIM "���%s����������������ˡ�\n"NOR, couple_ob->query("couple/couple_gender")+me->name(1)  ) ); 

                return 1;
        }
        
        if (!stringp(arg) || arg == "" || arg == " ") arg = "...";

        // Support of channel emote
        if( emote ) {
                string vb, emote_arg;

                if( sscanf(arg, "%s %s", vb, emote_arg) != 2 ) {
                        vb = arg;
                        emote_arg = "";
                }

                // If out support of channel emote and still send this message
                if (emote == 2){
                        tell_object( me, MAG + "��" + arg + NOR + "\n");
                        tell_object( couple_ob, MAG + couple_ob->query("couple/couple_gender")+me->name(1)+ arg + NOR +"\n");
                }else{
                        if (arg=="kiss") {
                            write( MAG "���鲻�Խ���ӵס"+me->query("couple/couple_gender")+couple_ob->name(1) +"�������һ�ǣ����...���...��\n" NOR);
                            tell_object(couple_ob, sprintf(HIM "���%s�����ӵס�㣬�����һ�ǣ����...���...��\n"NOR, couple_ob->query("couple/couple_gender")+me->name(1)  ) ); 
                        }else return do_emote(me,vb,emote_arg,couple_ob);
                }
                return 1;

        }
        else {
                write(sprintf(HIM "���%s˵��%s\n" NOR, me->query("couple/couple_gender")+couple_ob->name(1), arg ));
                tell_object(couple_ob, sprintf(HIM "%s����˵��%s\n" NOR, couple_ob->query("couple/couple_gender")+me->name(1), arg ));
        }

        return 1;
}

void create()
{
        set_name( HIY "����ָ" NOR, ({"marry ring", "ring"}) );
        set_weight(400);
        set( "no_get", 1);
        set( "no_put", 1 );
        set( "no_drop", "��Ľ���ָ���ܶ���,ֻ��ȥ����ׯ�����Լ��\n");
        set( "long", MAG+"����һö����ָ�������ʹ���������\n"+"\tcoupletalk ( ct )       �Ͱ��¶Ի���\n\n"+"\t֧�����ct, ct#, ct*\n"+NOR);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("material", "gold");
                set("armor_type", "finger");
                set("armor_prop/armor", 10);
                set("armor_prop/defense", 10);
                set("wear_msg", "$N��$n�ó���С�ĵش�����ָ�ϡ�\n");
                set("remove_msg", "$N��$nС�ĵش���ָ��ժ�����źá�\n");
        }
        
}




varargs mixed do_emote(object me, string verb, string arg,object couple_ob)
{
    string str, my_gender, target_gender, msg_postfix;
    string my_name,target_name;
    object target;
    mapping emote;

    if( !environment(me) ) return 0;

    emote=EMOTE_D->query_emote(verb);
    if ( !mapp(emote) || !sizeof(emote) ) return 0;

    my_name=couple_ob->query("couple/couple_gender")+me->name(1);
    if ( stringp(arg) && arg != "" ) {
        target = find_player(arg);

        if(!objectp(target)) {
            target = present(arg, environment(me));
            if( !objectp(target) ) return 0;
        }
        if (target!=couple_ob)        
        if( !target->is_character() || !me->visible(target) )
            return notify_fail("��Ҫ��˭�����������\n"); 

        target_gender = target->query("gender");
        target_name=target->name(1);
        if( target==me ) {
            msg_postfix = "_self";
            target = 0;
        }else{
            msg_postfix = "_target";
            if (target==couple_ob)
                target_name=me->query("couple/couple_gender")+target->name(1);
       }
    } else msg_postfix = "";

    my_gender = me->query("gender");

    if( stringp(str = emote["myself" + msg_postfix]) ) {
        str = replace_string(str, "$N", my_name);
        str = replace_string(str, "$P", gender_self(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
        if( objectp(target) ) {
                    str = replace_string(str, "$C", RANK_D->query_self_close(target));
                    str = replace_string(str, "$c", RANK_D->query_close(target));
                    str = replace_string(str, "$R", RANK_D->query_respect(target));
                    str = replace_string(str, "$r", RANK_D->query_rude(target));
            str = replace_string(str, "$n", target_name);
            str = replace_string(str, "$p", gender_pronoun(target_gender));
        }
        tell_object(me, HIM + str + NOR);
    }
    if( objectp(target) && target==couple_ob && stringp(str = emote["target"]) ) {
        str = replace_string(str, "$N", my_name);
        str = replace_string(str, "$P", gender_pronoun(my_gender));
        str = replace_string(str, "$S", RANK_D->query_self(me));
        str = replace_string(str, "$s", RANK_D->query_self_rude(me));
        str = replace_string(str, "$C", RANK_D->query_self_close(target));
        str = replace_string(str, "$c", RANK_D->query_close(target));
        str = replace_string(str, "$R", RANK_D->query_respect(target));
        str = replace_string(str, "$r", RANK_D->query_rude(target));
        str = replace_string(str, "$n", target_name);
        str = replace_string(str, "$p", gender_self(target_gender));
        tell_object(couple_ob, HIM + str + NOR);
        return 1;
    }
    if( stringp(str = emote["others"+msg_postfix]) ) {
        str = replace_string(str, "$N", my_name);
        str = replace_string(str, "$P", gender_pronoun(my_gender));
        str = replace_string(str, "$S", RANK_D->query_self(me));
        str = replace_string(str, "$s", RANK_D->query_self_rude(me));
        if( objectp(target) ) {
            str = replace_string(str, "$C", RANK_D->query_self_close(target));
            str = replace_string(str, "$c", RANK_D->query_close(target));
            str = replace_string(str, "$R", RANK_D->query_respect(target));
            str = replace_string(str, "$r", RANK_D->query_rude(target));
            str = replace_string(str, "$n", target_name);
            str = replace_string(str, "$p", gender_pronoun(target_gender));
        }
        tell_object(couple_ob, HIM + str + NOR);
    }
    return 1;
}
