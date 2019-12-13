
#include <ansi.h>
inherit F_CLEAN_UP;
string *skill_level_desc = ({
        BLU "��ѧէ��" NOR,
        YEL "��ͨƤë" NOR,
        GRN "��������" NOR,
        HIB "������" NOR,
        HIY "�������" NOR,
        YEL "�������" NOR,
        CYN "����似" NOR,
        HIG "�����뻯" NOR,
        HIC "�Ƿ��켫" NOR,
        CYN "һ����ʦ" NOR,
        HIW "��ɲ�" NOR,
        RED "��ɲ�" NOR,
        HIM "��ɲ�" NOR,
});

string *knowledge_level_desc = ({
        BLU "��ѧէ��" NOR,
        YEL "�����ž�" NOR,
        GRN "��֪һ��" NOR,
        HIB "������" NOR,
        HIY "����С��" NOR,
        YEL "�������" NOR,
        CYN "��Ȼ���" NOR,
        HIG "��Ȼ��ͨ" NOR,
        HIC "������˫" NOR,
        CYN "������" NOR,
        HIW "��ɲ�" NOR,
        RED "��ɲ�" NOR,
        HIM "��ɲ�" NOR,
        WHT "��豹���" NOR,
});

string skill_level(string, int);

int main(object me, string arg)
{
        object ob;
        mapping skl, lrn, map;
        string *sname, *mapped, str;
        int i,j;
        str = "";

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
				if ( !wizardp(me) && wizardp(ob) && ob->query("env/invisibility") )
					return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
        }

      if ( ob!=me && !wizardp(me)
                && !ob->is_apprentice_of(me)
                && !me->is_apprentice_of(ob)
                && !(ob->query("id") == me->query("couple/couple_id")) )
                return notify_fail("ֻ����ʦ����ʦͽ��ϵ���з��޹�ϵ�����ܲ쿴���˵ļ��ܡ�\n");


        skl = ob->query_skills();
        j = (int)sizeof(skl);
        if(!sizeof(skl)) {
                write( (ob==me ? "��" : ob->name()) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
                return 1;
        }
        write( (ob==me ? HIR"��" : ob->name()) + "Ŀǰ��ѧ���ļ����У�"NOR);
        str = "\n������������������������������������������������������������������\n\n";
        sname  = sort_array( keys(skl), (: strcmp :) );

        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);

        for(i=0; i<sizeof(skl); i++) {
				if (! objectp(find_object(SKILL_D(sname[i]))) &&
                    ! objectp(load_object(SKILL_D(sname[i]))))
                {
                        write(HIR "Error(No such skill):" + sname[i] + "\n" NOR);
                        continue;
                }
                        str = sprintf("%s%s%s%-40s" NOR " - %-10s %3d ��\n", str,	
                        (lrn[sname[i]] >= 2 * (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
//                           (member_array(sname[i], mapped)==-1? "  ": HIR"��"NOR),	
                             (member_array(sname[i], mapped)==-1? "  ": HIR"��"NOR),	
                        to_chinese(sname[i]) + " <" + sname[i] + ">",
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                         skl[sname[i]],// (int)lrn[sname[i]],	
                );
        }

		str += "\n��������������������������������������������"HIW"XYZX"NOR"������������������\n";	
		//str += HIG"Ŀǰ���� "+HIY""+ chinese_number(j) + ""HIG" �ּ��ܣ�" 
		//	+ "ӵ�м��ܵ�����"HIY+ob->query("xyzx_sys/skill_dian")
		//	+HIG"�����������ż��ܵȼ���"HIY+(ob->query("xyzx_sys/skill_dian")*MAX_SKILLS_ABOUT_DIAN-ob->query("skillup_add"))+"\n"NOR;
        this_player()->start_more(str);

        return 1;
}

string skill_level(string type, int level)
{
    int grade;
    if (level>=100) if (level<1500) grade=10+level/300 ;else return  NOR "��豹���" NOR;
    else    grade = level / 10;
    switch(type) {
        case "knowledge":
            if( grade >= sizeof(knowledge_level_desc) )
                grade = sizeof(knowledge_level_desc)-1;
            return knowledge_level_desc[grade];
            break;
        default:
            if( grade >= sizeof(skill_level_desc) )
                grade = sizeof(skill_level_desc)-1;
            return skill_level_desc[grade];
    }
}

int help(object me)
{
        write(@HELP
ָ���ʽ : skills|cha [<ĳ��>]

���ָ���������(��)��ѯ��ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ���������ż���� skills ���Բ�֪�Է���
����״����

��ʦ���Բ�ѯ�κ��˻� NPC �ļ���״����

HELP
    );
    return 1;
}
