// check.c

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object ob, man;
        mapping skl, lrn, map;
        string *sname, *mapped;
        int sp, dp;
        int i, cost;
        seteuid(getuid());
        foreach (man in all_inventory(environment(me))) {
                if( living(man) && !userp(man) ) break;
        }
        if (me->query("family/family_name") != "ؤ��" )
                return notify_fail("ֻ����ؤ���ܴ�̽���˵ļ��ܣ�\n");


        if ( !objectp(man) )
                return notify_fail("��Χû���ܰ���ȥ�˽���˵ļ��ܣ�\n");
        if ( me->query_skill("checking",1) < 10 )
                return notify_fail("��Ĵ�̽������δ���죬�޷��˽���˵ļ��ܣ�\n");
        if ( !arg )
                return notify_fail("��Ҫ����˭�ļ��ܣ�\n");
        if ( present(arg, environment(me)) )
                return notify_fail("��Ҫ�������˾��ڱ��ϣ��������ʲ����׵��ɣ�\n");
        ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ����˭�ļ��ܣ�\n");
        if ( ob == me )
                return notify_fail("��û���᱿�ɣ�Ҫ���˸������Լ��ļ��ܣ�\n");
     if(wizardp(ob) && !wizardp(me)) return notify_fail("��ʦ��Ҳ�ܲ飡����Ϊ��������ѽ......\n");
        cost = me->query("max_jing")/(me->query_skill("checking",1)/10) - 10;
        if ( me->query("jing") <= cost )
                return notify_fail("������̫���ˣ��޷�ȥ�������˵ļ��ܡ�\n");
        tell_object(me, "������ǰȥ��С���������" + man->name() + "��������" + ob->name() + "����� ...\n\n");
        message("vision", "ֻ��" + me->name() + "����Ц����" + man->name() + "˵�Ż��������ڴ���Щʲô��\n\n", 
                environment(me), ({ me, man }) );
        sp = me->query_skill("checking")*10 + me->query("kar")*5 + me->query("jing") + man->query("jing");
        dp = ob->query("kar")*5 + ob->query("jing")*2 + man->query("jing");

		if( random(man->query("jing")) > random(me->query_skill("checking")*10 + me->query("kar")*5 + me->query("jing")))
			return notify_fail( man->name() + "ҡ��ҡͷ��˵���������ҿɲ������" + RANK_D->query_respect(me) + "����ȥ����˴���һ�°ɣ�\n");
        
        if ( random(sp) < random(dp) )
                return notify_fail( man->name() + "ҡ��ҡͷ��˵���������ҿɲ������"
                        + RANK_D->query_respect(me) + "����ȥ����˴���һ�°ɣ�\n");
		
		if(cost<0)
			me->receive_damage("jing", 10 );
		else
			me->receive_damage("jing", cost );
		
		skl = ob->query_skills();
        
		if(!sizeof(skl)) {
                write( man->name() + "�����㣺 " + ob->name() + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
                return 1;
        }
        write( man->name() + "�����㣺 " + ob->name() +"Ŀǰ��ѧ���ļ��ܣ�\n\n");
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});
        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        
        i = random(sizeof(skl));
        cost = skl[sname[i]];
        if (random(20)<3)       cost=random(2*cost)+1;
        printf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
                (lrn[sname[i]] >= (cost+1) * (cost+1)) ? HIM : "",
                (member_array(sname[i], mapped)==-1? "  ": "��"),
                to_chinese(sname[i]) + " (" + sname[i] + ")",
                "/cmds/usr/skills"->skill_level(SKILL_D(sname[i])->type(), cost),
                cost, (int)lrn[sname[i]],
        );
        write("\n");
        return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : check [<ĳ��>]
���ָ������������������ѧ���ļ��ܡ�
��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills���Բ�֪�Է��ļ���״����
������Ϊؤ�����ר�ã�����ѧϰ��Ӧ�ļ��ܡ�
HELP
    );
    return 1;
}

