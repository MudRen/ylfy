
#include <ansi.h>
inherit F_CLEAN_UP;
string *skill_level_desc = ({
        BLU "初学乍练" NOR,
        YEL "粗通皮毛" NOR,
        GRN "半生不熟" NOR,
        HIB "马马虎虎" NOR,
        HIY "驾轻就熟" NOR,
        YEL "出类拔萃" NOR,
        CYN "神乎其技" NOR,
        HIG "出神入化" NOR,
        HIC "登峰造极" NOR,
        CYN "一代宗师" NOR,
        HIW "深不可测" NOR,
        RED "深不可测" NOR,
        HIM "深不可测" NOR,
});

string *knowledge_level_desc = ({
        BLU "新学乍用" NOR,
        YEL "初窥门径" NOR,
        GRN "略知一二" NOR,
        HIB "马马虎虎" NOR,
        HIY "已有小成" NOR,
        YEL "心领神会" NOR,
        CYN "了然於胸" NOR,
        HIG "豁然贯通" NOR,
        HIC "举世无双" NOR,
        CYN "震古铄今" NOR,
        HIW "深不可测" NOR,
        RED "深不可测" NOR,
        HIM "深不可测" NOR,
        WHT "返璞归真" NOR,
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
                if (!ob) return notify_fail("你要察看谁的技能？\n");
				if ( !wizardp(me) && wizardp(ob) && ob->query("env/invisibility") )
					return notify_fail("你要察看谁的技能？\n");
        }

      if ( ob!=me && !wizardp(me)
                && !ob->is_apprentice_of(me)
                && !me->is_apprentice_of(ob)
                && !(ob->query("id") == me->query("couple/couple_id")) )
                return notify_fail("只有巫师或有师徒关系或有夫妻关系的人能察看他人的技能。\n");


        skl = ob->query_skills();
        j = (int)sizeof(skl);
        if(!sizeof(skl)) {
                write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
                return 1;
        }
        write( (ob==me ? HIR"你" : ob->name()) + "目前所学过的技能有："NOR);
        str = "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
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
                        str = sprintf("%s%s%s%-40s" NOR " - %-10s %3d 级\n", str,	
                        (lrn[sname[i]] >= 2 * (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
//                           (member_array(sname[i], mapped)==-1? "  ": HIR"√"NOR),	
                             (member_array(sname[i], mapped)==-1? "  ": HIR"□"NOR),	
                        to_chinese(sname[i]) + " <" + sname[i] + ">",
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                         skl[sname[i]],// (int)lrn[sname[i]],	
                );
        }

		str += "\n━━━━━━━━━━━━━━━━━━━━━━"HIW"XYZX"NOR"━━━━━━━━━\n";	
		//str += HIG"目前共会 "+HIY""+ chinese_number(j) + ""HIG" 种技能，" 
		//	+ "拥有技能点数："HIY+ob->query("xyzx_sys/skill_dian")
		//	+HIG"，可提升独门技能等级："HIY+(ob->query("xyzx_sys/skill_dian")*MAX_SKILLS_ABOUT_DIAN-ob->query("skillup_add"))+"\n"NOR;
        this_player()->start_more(str);

        return 1;
}

string skill_level(string type, int level)
{
    int grade;
    if (level>=100) if (level<1500) grade=10+level/300 ;else return  NOR "返璞归真" NOR;
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
指令格式 : skills|cha [<某人>]

这个指令可以让你(你)查询所学过的技能。

你也可以指定一个和你有师徒关系的对象或你的配偶，用 skills 可以查知对方的
技能状况。

巫师可以查询任何人或 NPC 的技能状况。

HELP
    );
    return 1;
}
