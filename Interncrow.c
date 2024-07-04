#include <stdio.h>
#include <string.h>

#define MAX_JOBS 10
#define MAX_DOMAIN_LENGTH 50
#define MAX_ROLE_LENGTH 50


typedef struct {
    char domain[MAX_DOMAIN_LENGTH];
    char roles[MAX_JOBS][MAX_ROLE_LENGTH];
    int percentile;
} JobDomain;

int main() {
    JobDomain jobDomains[] = {
        { "Software Engineering", {"Developer", "Tester", "DevOps Engineer", "System Architect", ""}, 90},
        { "Data Science", {"Data Analyst", "Data Scientist", "Machine Learning Engineer", "Data Engineer", ""}, 85},
        { "Cybersecurity", {"Security Analyst", "Penetration Tester", "Security Architect", "Security Engineer", ""}, 80},
        { "Digital Marketing", {"SEO Specialist", "Content Marketer", "Social Media Manager", "Email Marketer", ""}, 70},
        { "Human Resources", {"Recruiter", "HR Manager", "Talent Acquisition Specialist", "HR Coordinator", ""}, 65}
    };

    int domainCount = sizeof(jobDomains) / sizeof(JobDomain);

    printf("Select a job domain to search for:\n");
    for (int i = 0; i < domainCount; i++) {
        printf("%d. %s (Percentile Score: %d%%)\n", i + 1, jobDomains[i].domain, jobDomains[i].percentile);
    }

    int choice;
    printf("Enter the number corresponding to the job domain: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > domainCount) {
        printf("Invalid choice. Exiting...\n");
        return 1;
    }

    printf("\nYou selected: %s\n", jobDomains[choice - 1].domain);
    printf("Percentile Score: %d%%\n", jobDomains[choice - 1].percentile);
    printf("Available Roles:\n");
    for (int i = 0; i < MAX_JOBS; i++) {
        if (strlen(jobDomains[choice - 1].roles[i]) > 0) {
            printf(" - %s\n", jobDomains[choice - 1].roles[i]);
        }
    }

    return 0;
}
